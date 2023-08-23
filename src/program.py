from typing import List, Dict, Set
import re
from predicate import Predicate
from copy import copy

PATCH = ('void assert(int cond) {\n  if (!(cond)) {\n  ERROR : {\n      reach_error();\n      abort();\n    }\n  '
         '       }\n}\n\nvoid assume(int cond) {\n  if (!cond) {\n    abort();\n  }\n}\n')

class Program:
    def  __init__(self, code: str):
        self.lines: List[str] = []
        self.assertion: Predicate = None # The assertion to add after the corresponding line number
        self.lemmas: List[Predicate] = [] # The lemmas to add after the corresponding line number
        assertion_points: Set[int] = set() # Potentially adding assertions right after these lines

        for line in code.split("\n"):
            if line.strip().split("(")[0] == "assert":
                assertion_points.add(len(self.lines) - 1)
                result = re.search(r'assert\((.*?)\);', line)
                self.assertion = Predicate(result.group(1), len(self.lines) - 1)
            else:
                self.lines.append(line)
                if line.strip().split()[0] in ["for", "do", "while"]:
                    assertion_points.add(len(self.lines) - 2)
                    assertion_points.add(len(self.lines) - 1)

        for i, l in enumerate(self.lines):
            print(i, l)
        print(assertion_points)
        print(self.assertion)

    @staticmethod
    def assume_predicate(lines: List[str], predicate: Predicate):
        lines[predicate.line_number] += f"\nassume({predicate.goal});"

    @staticmethod
    def assert_predicate(lines: List[str], predicate: Predicate):
        lines[predicate.line_number] += f"\nassert({predicate.goal});"

    def get_program_with_assertion(self, predicate: Predicate):
        lines = copy(self.lines)
        for lemma in self.lemmas:
            self.assume_predicate(lines, lemma)

        self.assert_predicate(lines, predicate)
        return PATCH + "\n".join([lines[i] for i in range(len(self.lines))])

