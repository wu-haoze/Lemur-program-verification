from typing import List, Set, Dict
import re
from predicate import Predicate
from copy import copy

PATCH = ('void assert(int cond) {\nif (!(cond)) {\nERROR : {\nreach_error();\nabort();\n }\n'
         '}\n}\nvoid assume(int cond) {\nif (!cond) {\nabort();\n}\n}\n')


class Program:
    def __init__(self, code: str, replacement: Dict[str,str]):
        self.lines: List[str] = []
        self.assertion: Predicate = None  # The assertion to add after the corresponding line number
        self.lemmas: List[Predicate] = []  # The lemmas to add after the corresponding line number
        self.assertion_points: Set[int] = set()  # Potentially adding assertions right after these lines

        self.replacement_for_GPT = replacement

        for line in code.split("\n"):
            if line.strip().split("(")[0] == "assert":
                self.assertion_points.add(len(self.lines) - 1)
                result = re.search(r'assert\((.*?)\);', line)
                self.assertion = Predicate(result.group(1), len(self.lines) - 1)
            elif line.strip().split("(")[0] == "assume":
                result = re.search(r'assume\((.*?)\);', line)
                self.lemmas.append(Predicate(result.group(1), len(self.lines) - 1))
            else:
                self.lines.append(line)
                if line.strip().split()[0] in ["for", "do", "while"]:
                    self.assertion_points.add(len(self.lines) - 2)
                    self.assertion_points.add(len(self.lines) - 1)

    @staticmethod
    def assume_predicate(lines: List[str], predicate: Predicate):
        lines[predicate.line_number] += f"\nassume({predicate.content});"

    @staticmethod
    def assert_predicate(lines: List[str], predicate: Predicate):
        lines[predicate.line_number] += f"\nassert({predicate.content});"

    def get_program_with_assertion(self, predicate: Predicate, assumptions:List[Predicate], forGPT: bool, dump=False):
        program = "" if forGPT else PATCH

        lines = copy(self.lines)
        if forGPT:
            for i, line in enumerate(lines):
                if line in self.replacement_for_GPT:
                    lines[i] = self.replacement_for_GPT[line]

        for lemma in self.lemmas:
            self.assume_predicate(lines, lemma)

        for assumption in assumptions:
            self.assume_predicate(lines, assumption)

        self.assert_predicate(lines, predicate)

        for line in lines:
            program += line + "\n"

        if dump:
            print("----------------------")
            print(program)
            print("----------------------")
        return program

    def dump(self):
        print("\nDumping program...")
        print("\nProgram without assertion:")
        for i, line in enumerate(self.lines):
            print(f"\t{i}: {line}")
        print("\nAssertion:")
        print(f"\tassert {self.assertion.content} after line {self.assertion.line_number}")
        print("\nLemmas:")
        for predicate in self.lemmas:
            print(f"\tassume {predicate.content} after line {predicate.line_number}")
        print("\nReplacements for GPT:")
        for before, after in self.replacement_for_GPT.items():
            print(f"\t{before} => {after}")

        print("\nPotential assertion points:")
        for line_number in self.assertion_points:
            print(f"After line {line_number}")

        print("\nDumping program - done\n")
