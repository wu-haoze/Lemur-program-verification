import tiktoken
import sys
import os
from task import Task
import utils
from os.path import dirname, join, basename
from rewriter import Rewriter
import yaml
from copy import copy
from program import Program

enc = tiktoken.encoding_for_model("gpt-3.5-turbo")

MAX_NUM_TOKENS = 150
import re

def is_integer(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

def contains_array_write(program):
    pattern = r"\w+\[\w+\] = (\w+);"
    # Find all matches of the pattern in the string
    matches = re.findall(pattern, program)
    print(matches)
    for match in matches:
        if is_integer(match):
            continue
        else:
            return True


def contains_array_access(assert_statement):
    # Regular expression to match array access (variable_name[...])
    array_access_pattern = r'\w+\s*\[(\w+)\]'

    # Search for array access pattern within the assert statement
    matches = re.findall(array_access_pattern, assert_statement)
    for match in matches:
        print("Assert", match)
        if not is_integer(match):
            return True
    return False


array_access = 0
index = 1
with open("benchmarks/benchmark_set_ssa_unsolved") as in_file:
    for line in in_file.readlines():
        yml_file = line.strip()
        if not os.path.isfile(yml_file):
            continue
        else:
            base_dir = dirname(yml_file)
            benchmark = basename(base_dir)
            data = utils.load_yaml_file(yml_file)
            code_path = join(base_dir, data["input_files"])
            if len(open(code_path, 'r').read().strip().split()) > MAX_NUM_TOKENS * 5:
                continue
            r = Rewriter(code_path)
            # print(code_path)
            program = Program(r.lines_to_verify, r.replacement)
            print(f"{line[:-1]},{program.number_of_loops}")
