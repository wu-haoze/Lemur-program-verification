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

MAX_NUM_TOKENS = 300
import re


array_access = 0
index = 1
with open("benchmarks/benchmark_set_reach_safety") as in_file:
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
            print(code_path)
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

                name = benchmark + "_" + data['input_files'][:-2] + f"_assertion{i}" + data['input_files'][-2:]
                yml_name = benchmark + "_" + os.path.basename(yml_file)[:-4] + f"_assertion{i}" + ".yml"
                new_data = copy(data)
                new_data["input_files"] = name
                print(f"{index},{yml_name},{num_tokens}")
                with open(f"/home/haozewu/GPT_MC/benchmarks/short_single_assertion_with_loop/c/{yml_name}", 'w') as f:
                    yaml.dump(new_data, f)
                with open(f"/home/haozewu/GPT_MC/benchmarks/short_single_assertion_with_loop/c/{name}", 'w') as out_file:
                    p = program.get_program_with_assertion(assertion, [], False)
                    out_file.write(p)

                if contains_array_access(assertion.content):
                    print(assertion.content)
                    array_access += 1
                index += 1
print(array_access)