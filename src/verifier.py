from typing import List, Dict

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
import time

class Result(Enum):
    Verified = 1
    Falsified = 2
    Unknown = 3

class Verifier:
    def __init__(self, task: Task, verifiers: List[str],  args):
        self.args = args
        self.verbosity = args.verbosity

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

        self.verifiers = verifiers
        self.log(0, f"Using Verifier: {self.verifiers}", 0)


        self.prompter = Prompter(self.program, self.prompt_dir, args.cache, args.model)
        self.log(0, f"Using model {args.model}", 0)

        self.query_id = 0

    def verify(self):
        assert(len(self.program.assertions) == 1)
        start = time.perf_counter()
        r, a = self.verify_goal(self.program.assertions[0], [], level=0)
        if r == Result.Verified:
            with open(join(self.working_dir, "result.txt"), 'w') as f:
                f.write(f"verified,{a},{time.perf_counter() - start}")
        if r == Result.Falsified:
            with open(join(self.working_dir, "result.txt"), 'w') as f:
                f.write(f"falsified,{a},{time.perf_counter() - start}")

    def verify_goal(self, goal: Predicate, assumptions: List[Predicate], level: int, recursive_mode: bool = True):
        timeout = self.args.per_instance_timeout

        self.log(1, f"Verifying goal: {goal.content} after line {goal.line_number} with timeout {timeout}", level)
        if level == 0:
            r = Result.Unknown
        else:
            r = self.run_verifier(goal, assumptions, timeout=timeout, level=level)

        if r == Result.Verified:
            self.log(1, f"Verified", level)
            return Result.Verified, 0
        elif r == Result.Falsified:
            self.log(1, f"Falsified", level)
            return Result.Falsified, 0
        elif recursive_mode:
            self.log(1, f"Unknown", level)
            self.log(1, f"Attempt to propose sub-goals...", level)
            if goal.line_number == min(self.program.assertion_points) and level > 0:
                proof_goals = []
            else:
                proof_goals = self.suggest_proof_goals(goal, level)
            self.log(1, f"Attempt to propose sub-goals - done", level)

            proof_goal_to_result : List[(List[Predicate], Result)] = []

            attempts = 0
            while len(proof_goals) > 0 or len(proof_goal_to_result) > 0:
                if attempts >= GC.MAX_ATTEMPT_AT_A_LEVEL:
                    break
                # Adapt
                if len(proof_goals) == 0:
                    self.log(1, "No potential sub-goal left. Adapt failed sub-goal...", level)
                    proof_goal_to_refine = None
                    proof_goal_to_strengthen = None
                    for i, (proof_goal, result) in enumerate(proof_goal_to_result):
                        if result == Result.Falsified and proof_goal_to_refine is None:
                            proof_goal_to_refine = i
                        if result == Result.Unknown and proof_goal_to_strengthen is None:
                            proof_goal_to_strengthen = i
                    if proof_goal_to_refine is not None:
                        i, proof_goal_to_adapt, falsified = proof_goal_to_refine, proof_goal_to_result[proof_goal_to_refine][0][0], True
                    elif proof_goal_to_strengthen is not None:
                        i, proof_goal_to_adapt, falsified = proof_goal_to_strengthen, proof_goal_to_result[proof_goal_to_strengthen][0][0], False
                    self.log(1,
                             (f"Adapting {proof_goal_to_adapt.content} after line {proof_goal_to_adapt.line_number}, "
                              f"falsified: {falsified}."),
                             level)
                    new_proof_goals = self.adapt_sub_goal(goal, proof_goal_to_adapt, falsified, level)
                    proof_goals += new_proof_goals

                    proof_goal_to_result = proof_goal_to_result[: i] + proof_goal_to_result[i + 1:]

                proof_goal = proof_goals[0]
                proof_goals = proof_goals[1:]
                attempts += 1

                content = ", ".join([f"{p.content} after line {p.line_number}" for p in proof_goal])

                self.log(1,
                         (f"Checking if the assertion is implied by {content}. "
                          f"Attempt {attempts}/{GC.MAX_ATTEMPT_AT_A_LEVEL}"), level)
                if proof_goal[0] == goal:
                    self.log(1, "Assumption same as goal. Skip", level)
                else:
                    r = self.run_verifier(goal, assumptions + proof_goal,
                                          timeout=self.args.per_instance_timeout, level=level)
                    if r == Result.Falsified:
                        self.log(1, f"Falsified", level)
                        return Result.Falsified, attempts
                    elif r != Result.Verified:
                        proof_goal_to_result.append((proof_goal, Result.Unknown))
                        self.log(1, "No", level)
                        continue
                    else:
                        self.log(1, "Yes!", level)
                        all_hold = True
                        # We need to verify a /\ b /\ c
                        # Instead we verify ((b /\ c) -> a) and (c -> b) and c
                        for pred_id, predicate in enumerate(proof_goal):
                            recursive_mode = len(proof_goal[pred_id + 1:]) == 0
                            r, a = self.verify_goal(predicate, assumptions + proof_goal[pred_id + 1:], level + 1, recursive_mode)
                            if r == Result.Verified:
                                continue
                            elif r == Result.Falsified:
                                # We might want to try something smarter here
                                proof_goal_to_result.append((proof_goal, Result.Falsified))
                                all_hold = False
                                break
                            else:
                                all_hold = False
                                break
                        if all_hold:
                            self.log(1, f"Sub-goal proven", level)
                            self.log(1, "Verified", level)
                            return Result.Verified, attempts
                        else:
                            # There is another we could prove the assertion.
                            # If proof_goal has length 1 and is not in loop, we already know proof_goal -> goal,
                            # we could be done if -proof_goal -> goal.
                            if len(proof_goal) == 1:
                                ln = proof_goal[0].line_number
                                if AssertionPointAttributes.InLoop not in self.program.assertion_points[ln]:
                                    predicate = Predicate(f"!({proof_goal[0].content})", proof_goal[0].line_number)
                                    content = f"{predicate.content} after line {predicate.line_number}"
                                    self.log(1,
                                             f"Checking if the assertion is also implied by {content}.", level)

                                    r = self.run_verifier(goal, assumptions + [predicate],
                                                          timeout=self.args.per_instance_timeout, level=level)
                                    if r == Result.Verified:
                                        self.log(1, "Yes!", level)
                                        self.log(1, f"Verified", level)
                                        return Result.Verified, attempts
                                    else:
                                        self.log(1, "No", level)
                            continue

            self.log(1, f"Unknown", level)
            return Result.Unknown, attempts

    def suggest_proof_goals(self, goal : Predicate, level : int)->List[List[Predicate]]:
        predicates = self.prompter.suggest_predicate(goal, self.args.num_assertions, self.args.num_attempts,
                                                     simulate=self.args.simulate)
        self.log(1, f"Found {len(predicates)} potential sub-goals", level)

        for i, predicate in enumerate(predicates):
            content =  ", ".join([f"{p.content} after line {p.line_number}" for p in predicate])
            self.log(1, f"Goal {i + 1}: {content}", level)
        return predicates

    def adapt_sub_goal(self, goal : Predicate, current_sub_goal : Predicate,
                       falsified : bool, level : int)->List[List[Predicate]]:
        predicates = self.prompter.adapt_predicate(goal, current_sub_goal,
                                                   falsified,
                                                   self.args.num_attempts,
                                                   simulate=self.args.simulate)
        self.log(1, f"Found {len(predicates)} potential adapted sub-goals", level)

        for i, predicate in enumerate(predicates):
            content =  ", ".join([f"{p.content} after line {p.line_number}" for p in predicate])
            self.log(1, f"Goal {i + 1}: {content}", level)
        return predicates

    def add_lemma(self, goal: Predicate):
        self.program.lemmas.append(goal)

    def run_verifier(self, goal: Predicate, assumptions: List[Predicate], timeout : int, level: int)-> Result:
        self.query_id += 1
        p = self.program.get_program_with_assertion(goal, assumptions, {}, False, dump=True)
        filename = join(self.code_dir, f"code_{self.query_id}.c")
        with open(filename, 'w') as out_file:
            out_file.write(p)

        for verifier in self.verifiers:
            if "uautomizer" in verifier:
                self.log(1, f"Trying {basename(verifier)}", level)
                os.chdir(dirname(verifier))
                command = f"python3 -u {verifier} --spec {self.property} --file {filename} --architecture {self.arch} --full-output"
                to = timeout
            elif "esbmc" in verifier:
                self.log(1, f"Trying {basename(verifier)}", level)
                os.chdir(dirname(verifier))
                command = f"python3 -u {verifier} -p {self.property} -s kinduction --arch {self.arch.split('bit')[0]} {filename}"
                to = min(10, timeout)
            stdout, _ = run_subprocess(command, self.verbosity > 1, to)

            command = f"pkill -9 java; pkill -9 z3; pkill -9 esbmc; pkill -9 mathsat"
            run_subprocess(command, self.verbosity > 1, timeout)

            if stdout[-1] == "TRUE\n":
                return Result.Verified
            elif stdout[-1] == "FALSE\n" or stdout[-1] == "FALSE_REACH\n":
                return Result.Falsified
            else:
                continue

        return Result.Unknown

    def log(self, verbosity: int, message: str, level: int = 0):
        if self.verbosity >= verbosity:
            message = bold(f"Level {level} - ") + message
            print(message)
