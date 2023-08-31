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


def contains_array_access(assert_statement):
    # Regular expression to match array access (variable_name[...])
    array_access_pattern = r'\w+\s*\[[^\]]+\]'

    # Search for array access pattern within the assert statement
    matches = re.findall(array_access_pattern, assert_statement)
    for match in matches:
        if not is_integer(match):
            return True
    return False


array_access = 0
index = 1
with open("benchmarks/benchmark_set_reach_safety_short_single_assertion_with_loop_unsolved") as in_file:
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

                p = program.get_program_with_assertion(assertion, [], True)

                if len(p.split()) > MAX_NUM_TOKENS * 2:
                    continue
                num_tokens = len(enc.encode(p))
                if num_tokens > MAX_NUM_TOKENS:
                    continue
                if contains_array_access(assertion.content):
                    continue
                else:
                    array_access += 1

                name = data['input_files']
                yml_name = os.path.basename(yml_file)[:-4] + ".yml"
                new_data = copy(data)
                new_data["input_files"] = name
                print(f"{index},{yml_name},{num_tokens},{assertion.content}")
                with open(
                        f"/home/haozewu/GPT_MC/benchmarks/short_single_assertion_with_loop_unsolved_no_array_access/c/{yml_name}",
                        'w') as f:
                    yaml.dump(new_data, f)
                with open(
                        f"/home/haozewu/GPT_MC/benchmarks/short_single_assertion_with_loop_unsolved_no_array_access/c/{name}",
                        'w') as out_file:
                    p = program.get_program_with_assertion(assertion, [], False)
                    out_file.write(p)

                index += 1
