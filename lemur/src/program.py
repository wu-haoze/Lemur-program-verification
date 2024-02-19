from enum import Enum
from typing import List, Set, Dict
import re
from predicate import Predicate
from copy import copy
from utils import blue

PATCH = ('void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }\n'
         'void assume(int cond) { if (!cond) { abort(); } }\n')


class AssertionPointAttributes(Enum):
    BeforeLoop = 1
    InLoop = 2
    BeforeAssertion = 3
    BeginningOfLoop = 4
    EndOfLoop = 5

class Program:
    def __init__(self, lines: List[str], replacement: Dict[str, str]):
        self.lines: List[str] = []
        self.assertions: List[Predicate] = []  # The assertion to add after the corresponding line number
        self.lemmas: List[Predicate] = []  # The lemmas to add after the corresponding line number
        self.assertion_points: Dict[
            int, Set[AssertionPointAttributes]] = {}  # Potentially adding assertions right after these lines

        self.replacement_for_GPT = replacement
        self.in_loop: Dict[int, int] = dict()
        self.unclosed_brackets: Dict[int, int] = {-1: 0}

        self.number_of_loops = 0

        last_line_in_loop = False
        left_bracket = 0
        for line in lines:
            if last_line_in_loop:
                self.in_loop[len(self.lines) - 1] = True
            else:
                self.in_loop[len(self.lines) - 1] = False

            if last_line_in_loop and "{" in line:
                left_bracket += 1
            if last_line_in_loop and "}" in line:
                left_bracket -= 1
                if left_bracket == 0:
                    self.add_assertion_point(len(self.lines), AssertionPointAttributes.EndOfLoop)
                    #self.add_assertion_point(len(self.lines) - 1, AssertionPointAttributes.InLoop)
                    last_line_in_loop = False

            if line.strip().split("(")[0] == "assert":
                self.add_assertion_point(len(self.lines) - 1, AssertionPointAttributes.BeforeAssertion)
                if last_line_in_loop:
                    self.add_assertion_point(len(self.lines) - 1, AssertionPointAttributes.InLoop)

                result = re.search(r'assert\((.*?)\);', line)
                self.assertions.append(Predicate(result.group(1), len(self.lines) - 1))
            elif line.strip().split("(")[0] == "assume":
                result = re.search(r'assume\((.*?)\);', line)
                self.lemmas.append(Predicate(result.group(1), len(self.lines) - 1))
            else:
                self.lines.append(line)
                if line.strip().split()[0] in ["for", "do", "while"]:
                    self.number_of_loops += 1
                    self.add_assertion_point(len(self.lines) - 2, AssertionPointAttributes.BeforeLoop)
                    if last_line_in_loop:
                        self.add_assertion_point(len(self.lines) - 2, AssertionPointAttributes.InLoop)
                    self.add_assertion_point(len(self.lines) - 1, AssertionPointAttributes.InLoop)
                    self.add_assertion_point(len(self.lines) - 1, AssertionPointAttributes.BeginningOfLoop)
                    if not last_line_in_loop:
                        assert ("{" in line)
                        left_bracket += 1
                    last_line_in_loop = True
                if "{" in line:
                    if "}" not in line:
                        self.unclosed_brackets[len(self.lines) - 1] = self.unclosed_brackets[len(self.lines) - 2] + 1
                    else:
                        self.unclosed_brackets[len(self.lines) - 1] = self.unclosed_brackets[len(self.lines) - 2]
                elif "}" in line:
                    self.unclosed_brackets[len(self.lines) - 1] = self.unclosed_brackets[len(self.lines) - 2] - 1
                else:
                    self.unclosed_brackets[len(self.lines) - 1] = self.unclosed_brackets[len(self.lines) - 2]

        self.in_loop[len(self.lines) - 1] = False
        if self.number_of_loops > 0:
            del self.assertion_points[min(self.assertion_points)]


    def add_assertion_point(self, line_number: int, attribute: AssertionPointAttributes):
        if line_number not in self.assertion_points:
            self.assertion_points[line_number] = set()
        self.assertion_points[line_number].add(attribute)

    @staticmethod
    def assume_predicate(lines: List[str], predicate: Predicate):
        lines[predicate.line_number] += f"\nassume({predicate.content});"

    @staticmethod
    def assert_predicate(lines: List[str], predicate: Predicate):
        lines[predicate.line_number] += f"\nassert({predicate.content});"

    def get_program_with_assertion(self, predicate: Predicate, assumptions: List[Predicate],
                                   assertion_points: Dict[int,str],
                                   forGPT : bool,
                                   dump=False):
        program = "" if forGPT else PATCH

        lines = copy(self.lines)
        if forGPT:
            for i, line in enumerate(lines):
                if line in self.replacement_for_GPT:
                    lines[i] = self.replacement_for_GPT[line]

        for lemma in self.lemmas:
            self.assume_predicate(lines, lemma)

        for line_number, name in assertion_points.items():
            lines[line_number] += f"\n// Line {name}"

        for assumption in assumptions:
            self.assume_predicate(lines, assumption)

        self.assert_predicate(lines, predicate)

        if forGPT:
            for i, line in enumerate(lines):
                if i < predicate.line_number:
                    program += line + "\n"
                elif i >= predicate.line_number and (not self.in_loop[i]):
                    program += line + "\n"
                    for m in range(self.unclosed_brackets[i]):
                        if m == self.unclosed_brackets[i] - 1:
                            program += "return 1;\n"
                        program += "}\n"
                    break
                else:
                    program += line + "\n"
        else:
            for line in lines:
                program += line + "\n"
        program = program[:-1]

        if dump:
            print("----------------------")
            print(blue(program))
            print("----------------------")
        return program

    def decide_assertion_point(self, goal: Predicate):
        """
        - If the assertion is in the loop:
            - if the assertion is the first line of the loop
                - beginning of the loop
            - else:
                - before the assertion
        - else:
            - the beginning of the closest loop
        """
        print("Deciding assertion point...")
        closest_line = None
        if AssertionPointAttributes.InLoop in self.assertion_points[goal.line_number]:
            if AssertionPointAttributes.BeginningOfLoop in self.assertion_points[goal.line_number]:
                #print("assertion is the beginning of the loop, get the line right before the loop")
                assert(AssertionPointAttributes.BeforeLoop in self.assertion_points[goal.line_number - 1])
                closest_line = goal.line_number - 1
            else:
                #print("assertion is in the loop, find the beginning of the closest loop")
                tmp = goal.line_number
                while tmp >= 0:
                    tmp -= 1
                    if (tmp in self.assertion_points and
                            AssertionPointAttributes.BeginningOfLoop in self.assertion_points[tmp]):
                        closest_line = tmp
                        break
        else:
            #print("assertion is right after a loop, find the beginning of the closest loop")
            tmp = goal.line_number
            while tmp >= 0:
                tmp -= 1
                if (tmp in self.assertion_points and (not self.in_loop[tmp - 1]) and
                        AssertionPointAttributes.BeginningOfLoop in self.assertion_points[tmp]):
                    closest_line = tmp
                    break

        if closest_line is None:
            return None, None
        else:
            print(f"Deciding assertion point done: picked line {closest_line}.")
        return closest_line, self.assertion_points[closest_line]

    def dump(self):
        print("\nDumping program...")
        print("\nProgram without assertion:")
        for i, line in enumerate(self.lines):
            print(f"\t{i}: {line} // In loop: {self.in_loop[i]}, unclosed bracket: {self.unclosed_brackets[i]}")
        print("\nAssertion:")
        for assertion in self.assertions:
            print(f"\tassert {assertion.content} after line {assertion.line_number}")
        print("\nLemmas:")
        for predicate in self.lemmas:
            print(f"\tassume {predicate.content} after line {predicate.line_number}")
        print("\nReplacements for GPT:")
        for before, after in self.replacement_for_GPT.items():
            print(f"\t{before} => {after}")

        print("\nPotential assertion points:")
        for line_number, attributes in self.assertion_points.items():
            print(f"After line {line_number}: {', '.join(map(lambda x: x.name, attributes))}")

        print("\nDumping program - done\n")
