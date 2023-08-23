from typing import List

from task import Task
from utils import create_working_dir, run_subprocess
import os
from shutil import copy
from os.path import join, basename, dirname
from rewritter import Rewritter
from predicate import Predicate
from enum import Enum
import gloal_configurations as GC
from program import Program

PATCH = ('void assert(int cond) {\n  if (!(cond)) {\n  ERROR : {\n      reach_error();\n      abort();\n    }\n  '
         '       }\n}\n\nvoid assume(int cond) {\n  if (!cond) {\n    abort();\n  }\n}\n')

import random


class Result(Enum):
    Verified = 1
    Falsified = 2
    Unknown = 3

class Verifier:
    def  __init__(self, task: Task, verifier: str,  args):
        self.working_dir, self.prompt_dir, self.code_dir = create_working_dir(args.working_dir, task.source_code, args.prop)
        os.chdir(self.working_dir)
        self.initialize_verification(task)
        self.verifier = verifier

        self.verbosity = args.verbosity

    def initialize_verification(self, task : Task):
        # copy over the c file and the property file
        self.c_program = join(self.working_dir, "base.c")
        self.property = join(self.working_dir, "property")
        self.arch = task.arch
        copy(task.source_code, self.c_program)
        copy(task.property, self.property)

        r = Rewritter(self.c_program, open(self.c_program).read().strip())
        self.program = Program(r.new_code)
        p = self.program.get_program_with_assertion(self.program.assertion)
        print(p)

        with open(join(self.working_dir, "temp.c"), 'w') as out_file:
            out_file.write(PATCH)
            out_file.write(r.new_code)
        print(r.new_code)
        self.c_program = join(self.working_dir, "temp.c")

    def verify(self):
        self.verify_goal("assert(test goal);", level=0)

    def verify_goal(self, goal, level: int):
        self.log(2, f"Verifying goal: {goal}", level)
        r = self.run_verifier(goal)
        if r == Result.Verified:
            self.log(2, f"Verified", level)
            return Result.Verified
        elif r == Result.Falsified:
            self.log(2, f"Falsified", level)
            return Result.Falsified
        else:
            self.log(2, f"Unknown", level)
            for attempt in range(GC.NUM_ATTEMPTS_FOR_PREDICATE_SUGGESTIONS):
                self.log(2, f"Attempt {attempt} to propose sub-goals...", level)
                proof_goals = self.suggest_proof_goals(goal)
                self.log(2, f"Found sub-goals to prove: {proof_goals}", level)
                all_verified = True
                for proof_goal in proof_goals:
                    r = self.verify_goal(proof_goal, level + 1)
                    if r == Result.Verified:
                        self.add_lemma(proof_goal)
                    elif r == Result.Falsified:
                        # We might want to try something smarter here
                        all_verified = False
                        break
                    else:
                        all_verified = False
                        break
                if not all_verified:
                    continue
                else:
                    self.log(2, f"Verified with sub-goal", level)
                    return Result.Verified
            self.log(2, f"Unknown", level)
            return Result.Unknown

    def suggest_proof_goals(self, goal):
        return [goal + "_1", goal + "_2"]

    def add_lemma(self, goal):
        return

    def run_verifier(self, goal):
        r = random.random()
        if r < 0.4:
            return Result.Verified
        elif r < 0.7:
            return Result.Falsified
        else:
            return Result.Unknown

        os.chdir(dirname(self.verifier))
        command = f"python3 -u {self.verifier} --spec {self.property} --file {self.c_program} --architecture {self.arch} --full-output"
        print(command)
        run_subprocess(command)
        os.chdir(self.working_dir)

    def log(self, verbosity: int, message: str, level: int):
        if self.verbosity >= verbosity:
            for i in range(level):
                message = "\t" + message
            print(message)