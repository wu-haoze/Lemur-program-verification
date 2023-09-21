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
from predicate import Predicate

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
    array_access_pattern = r'\w+\s*\[(\w+)\]'

    # Search for array access pattern within the assert statement
    matches = re.findall(array_access_pattern, assert_statement)
    for match in matches:
        if not is_integer(match):
            return True
    return False

def contains_array_write(program):
    for line in program.split("\n"):
        pattern = r"\w+\[\w+\] = "
        # Find all matches of the pattern in the string
        matches = re.findall(pattern, line)
        for match in matches:
            rhs = line.split(match)[1][:-1].strip();
            if is_integer(rhs):
                continue
            else:
                return True
    return False

array_access = 0
index = 1
with open("benchmarks/benchmark_set_unsolved") as in_file:
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
            r = Rewriter(code_path, handle_reach_error=False)
            program = Program(r.lines_to_verify, r.replacement)

            if program.number_of_loops == 0:
                continue

            p = program.get_program_with_assertion(Predicate("", len(program.lines) - 1), [], True)
            if len(p.split()) > MAX_NUM_TOKENS * 2:
                continue
            num_tokens = len(enc.encode(p))
            if num_tokens > MAX_NUM_TOKENS:
                continue

            r = Rewriter(code_path, handle_reach_error=True)
            program = Program(r.lines_to_verify, r.replacement)
            if r.has_reach_error:
                print(code_path)
                continue

            for i, assertion in enumerate(program.assertions):
                p = program.get_program_with_assertion(assertion, [], True)
                if contains_array_write(p):
                    continue
                if contains_array_access(assertion.content):
                    continue
                if len(p.split()) > MAX_NUM_TOKENS * 2:
                    continue
                num_tokens = len(enc.encode(p))
                if num_tokens > MAX_NUM_TOKENS:
                    continue

                name = data['input_files'][:-2] + data['input_files'][-2:]
                yml_name = os.path.basename(yml_file)[:-4] + ".yml"
                new_data = copy(data)
                new_data["input_files"] = name
                print(f"{index},{yml_name},{num_tokens}")
                with open(f"/home/haozewu/GPT_MC/benchmarks/short_hard_benchmarks/c/{yml_name}", 'w') as f:
                    yaml.dump(new_data, f)
                with open(f"/home/haozewu/GPT_MC/benchmarks/short_hard_benchmarks/c/{name}", 'w') as out_file:
                    p = program.get_program_with_assertion(assertion, [], False)
                    out_file.write(p)

                    array_access += 1
                index += 1
print(array_access)