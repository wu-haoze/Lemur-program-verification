from typing import List

from task import Task
from utils import create_working_dir, run_subprocess_and_get_output, run_subprocess
import os
from shutil import copy
from os.path import join, basename, dirname
from rewritter import Rewritter
from predicate import Predicate
from enum import Enum
import gloal_configurations as GC
from program import Program
import random
from prompter import Prompter

class Result(Enum):
    Verified = 1
    Falsified = 2
    Unknown = 3

class Verifier:
    def  __init__(self, task: Task, verifier: str,  args):
        self.working_dir, self.prompt_dir, self.code_dir = \
            create_working_dir(args.working_dir, task.source_code, args.prop)
        os.chdir(self.working_dir)
        # copy over the c file and the property file
        self.c_program = join(self.working_dir, "base.c")
        self.property = join(self.working_dir, "property")
        self.arch = task.arch
        copy(task.source_code, self.c_program)
        copy(task.property, self.property)

        self.original_program = open(self.c_program).read().strip()
        r = Rewritter(self.c_program, self.original_program)
        self.program = Program(r.new_code_to_verify, r.replacement)

        self.program.dump()

        self.verifier = verifier
        os.chdir(dirname(self.verifier))
        self.verbosity = args.verbosity

        self.prompter = Prompter(self.program, self.prompt_dir, args.cache)

        self.query_id = 0

    def verify(self):
        self.verify_goal(self.program.assertion, level=0)

    def verify_goal(self, goal, level: int):
        self.log(1, f"Verifying goal: {goal.content} at line {goal.line_number}", level)
        r = self.run_verifier(goal, [], timeout=20)

        if r == Result.Verified:
            self.log(1, f"Verified", level)
            return Result.Verified
        elif r == Result.Falsified:
            self.log(1, f"Falsified", level)
            return Result.Falsified
        else:
            self.log(1, f"Unknown", level)
            self.log(1, f"Attempt to propose sub-goals...", level)
            proof_goals = self.suggest_proof_goals(goal, level)
            for proof_goal in proof_goals:
                if proof_goal == goal:
                    continue
                self.log(1,
                         f"Checking if {proof_goal.content} after line {proof_goal.line_number} "
                         f"implies the assertion...", level)
                if self.run_verifier(goal, [proof_goal], timeout=20) != Result.Verified:
                    self.log(1, "No", level)
                    continue
                else:
                    self.log(1, "Yes!", level)
                    r = self.verify_goal(proof_goal, level + 1)
                    if r == Result.Verified:
                        self.add_lemma(proof_goal)
                        self.log(1, f"Sub-goal proven", level)
                        self.log(1, "Verified", level)
                        return Result.Verified
                    elif r == Result.Falsified:
                        # We might want to try something smarter here
                        continue
                    else:
                        continue

            self.log(1, f"Unknown", level)
            return Result.Unknown

    def suggest_proof_goals(self, goal : Predicate, level : int):
        predicates = self.prompter.suggest_predicate(goal, simulate=False)
        self.log(1, f"Found {len(predicates)} sub-goals to prove", level)

        for i, predicate in enumerate(predicates):
            self.log(1, f"Goal {i + 1}: {predicate.content} after line {predicate.line_number}", level)
        return predicates

    def add_lemma(self, goal: Predicate):
        self.program.lemmas.append(goal)

    def run_verifier(self, goal: Predicate, assumptions: List[Predicate], timeout:int = 20)-> Result:
        self.query_id += 1
        p = self.program.get_program_with_assertion(goal, assumptions, False, dump=True)
        filename = join(self.code_dir, f"code_{self.query_id}.c")
        with open(filename, 'w') as out_file:
            out_file.write(p)

        command = f"python3 -u {self.verifier} --spec {self.property} --file {filename} --architecture {self.arch} --full-output"
        self.log(3, command)


        stdout, _ = run_subprocess(command, self.verbosity > 1, timeout)
        if stdout[-1] == "TRUE\n":
            return Result.Verified
        elif stdout[-1] == "FALSE\n":
            return Result.Falsified
        else:
            return Result.Unknown

    def log(self, verbosity: int, message: str, level: int = 0):
        if self.verbosity >= verbosity:
            for i in range(level):
                message = "  " + message
            print(message)
