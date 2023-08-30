from typing import List

from task import Task
from utils import create_working_dir, run_subprocess_and_get_output, run_subprocess, bold
import os
from shutil import copy
from os.path import join, basename, dirname
from rewriter import Rewriter
from predicate import Predicate
from enum import Enum
import gloal_configurations as GC
from program import Program, AssertionPointAttributes
import random
from prompter import Prompter

class Result(Enum):
    Verified = 1
    Falsified = 2
    Unknown = 3

class Verifier:
    def __init__(self, task: Task, verifier: str,  args):
        self.args = args
        self.working_dir, self.prompt_dir, self.code_dir = \
            create_working_dir(args.working_dir, task.source_code, args.prop)
        os.chdir(self.working_dir)
        # copy over the c file and the property file
        self.c_program = join(self.working_dir, "base.c")
        self.property = join(self.working_dir, "property")
        self.arch = task.arch
        copy(task.source_code, self.c_program)
        copy(task.property, self.property)

        r = Rewriter(self.c_program)
        self.program = Program(r.lines_to_verify, r.replacement)

        self.program.dump()

        self.verifier = verifier
        os.chdir(dirname(self.verifier))
        self.verbosity = args.verbosity

        self.prompter = Prompter(self.program, self.prompt_dir, args.cache)

        self.query_id = 0

    def verify(self):
        assert(len(self.program.assertions) == 1)
        self.verify_goal(self.program.assertions[0], [], level=0)

    def verify_goal(self, goal: Predicate, assumptions: List[Predicate], level: int):
        if goal.line_number == min(self.program.assertion_points):
            timeout = 43200
        else:
            timeout = self.args.per_instance_timeout
        self.log(1, f"Verifying goal: {goal.content} after line {goal.line_number} with timeout {timeout}", level)
        r = self.run_verifier(goal, assumptions, timeout=timeout)

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
            self.log(1, f"Attempt to propose sub-goals - done", level)
            for proof_goal_id, proof_goal in enumerate(proof_goals):
                content = ", ".join([f"{p.content} after line {p.line_number}" for p in proof_goal])

                self.log(1,
                         f"Checking if the assertion is implied by {content}...", level)
                if proof_goal == goal:
                    self.log(1, "Assumption same as goal. Skip", level)
                else:
                    if self.run_verifier(goal, assumptions + proof_goal,
                                         timeout=self.args.per_instance_timeout) != Result.Verified:
                        self.log(1, "No", level)
                        continue
                    else:
                        all_hold = True
                        # We need to verify a /\ b /\ c
                        # Instead we verify ((b /\ c) -> a) and (c -> b) and c
                        for pred_id, predicate in enumerate(proof_goal):
                            self.log(1, "Yes!", level)
                            r = self.verify_goal(predicate, proof_goal[pred_id + 1:], level + 1)
                            if r == Result.Verified:
                                continue
                            elif r == Result.Falsified:
                                # We might want to try something smarter here
                                all_hold = False
                                break
                            else:
                                all_hold = False
                                break
                        if all_hold:
                            self.log(1, f"Sub-goal proven", level)
                            self.log(1, "Verified", level)
                            return Result.Verified
                        else:
                            continue

            self.log(1, f"Unknown", level)
            return Result.Unknown

    def suggest_proof_goals(self, goal : Predicate, level : int)->List[List[Predicate]]:
        predicates = self.prompter.suggest_predicate(goal, self.args.num_assertions, self.args.num_attempts,
                                                     simulate=self.args.simulate)
        self.log(1, f"Found {len(predicates)} potential sub-goals", level)

        for i, predicate in enumerate(predicates):
            content =  ", ".join([f"{p.content} after line {p.line_number}" for p in predicate])
            self.log(1, f"Goal {i + 1}: {content}", level)
        return predicates

    def add_lemma(self, goal: Predicate):
        self.program.lemmas.append(goal)

    def run_verifier(self, goal: Predicate, assumptions: List[Predicate], timeout : int)-> Result:
        self.query_id += 1
        p = self.program.get_program_with_assertion(goal, assumptions, False, dump=True)
        filename = join(self.code_dir, f"code_{self.query_id}.c")
        with open(filename, 'w') as out_file:
            out_file.write(p)

        command = f"python3 -u {self.verifier} --spec {self.property} --file {filename} --architecture {self.arch} --full-output"

        stdout, _ = run_subprocess(command, self.verbosity > 1, timeout)

        command = f"pkill -9 java; pkill -9 z3"
        run_subprocess(command, self.verbosity > 1, timeout)


        if stdout[-1] == "TRUE\n":
            return Result.Verified
        elif stdout[-1] == "FALSE\n":
            return Result.Falsified
        else:
            return Result.Unknown

    def log(self, verbosity: int, message: str, level: int = 0):
        if self.verbosity >= verbosity:
            message = bold(f"Level {level} - ") + message
            print(message)
