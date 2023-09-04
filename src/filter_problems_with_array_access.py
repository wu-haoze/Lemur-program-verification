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
with open("benchmarks/benchmark_set_reach_safety_short_hard_benchmarks") as in_file:
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
            if program.number_of_loops == 0:
                continue

            for i, assertion in enumerate(program.assertions):

                p = program.get_program_with_assertion(assertion, [], False)
                if contains_array_write(p):
                    continue
                if contains_array_access(assertion.content):
                    continue
                else:
                    array_access += 1

                name = data['input_files']
                yml_name = os.path.basename(yml_file)[:-4] + ".yml"
                new_data = copy(data)
                new_data["input_files"] = name
                print(f"{index},{yml_name},{assertion.content}")
                with open(
                        f"/home/haozewu/GPT_MC/benchmarks/short_hard_benchmarks_no_random_write_to_array/c/{yml_name}",
                        'w') as f:
                    yaml.dump(new_data, f)
                with open(
                        f"/home/haozewu/GPT_MC/benchmarks/short_hard_benchmarks_no_random_write_to_array/c/{name}",
                        'w') as out_file:
                    p = program.get_program_with_assertion(assertion, [], False)
                    out_file.write(p)

                index += 1
