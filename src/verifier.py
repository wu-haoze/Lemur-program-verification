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
        self.working_dir, self.prompt_dir, self.code_dir = create_working_dir(args.working_dir, task.source_code, args.prop)
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

        self.prompter = Prompter(self.program, self.prompt_dir)

        self.query_id = 0

    def verify(self):
        self.verify_goal(self.program.assertion, level=0)

    def verify_goal(self, goal, level: int):
        self.log(2, f"Verifying goal: {goal.content} at line {goal.line_number}", level)
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

    def run_verifier(self, goal: Predicate)-> Result:
        self.query_id += 1
        p = self.program.get_program_with_assertion(goal, False)
        filename = join(self.code_dir, f"code_{self.query_id}.c")
        with open(filename, 'w') as out_file:
            out_file.write(p)

        print(p)
        command = f"python3 -u {self.verifier} --spec {self.property} --file {filename} --architecture {self.arch} --full-output"
        print(command)
        stdout, _ = run_subprocess(command, self.verbosity > 1)
        if stdout[-1] == "TRUE\n":
            return Result.Verified
        elif stdout[-1] == "FALSE\n":
            return Result.Falsified
        else:
            return Result.Unknown

    def log(self, verbosity: int, message: str, level: int):
        if self.verbosity >= verbosity:
            for i in range(level):
                message = "\t" + message
            print(message)
