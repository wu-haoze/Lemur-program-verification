import tiktoken
import sys
import os
from task import Task
import utils
from os.path import dirname, join
from rewriter import Rewriter
import yaml
from copy import copy

enc = tiktoken.encoding_for_model("gpt-3.5-turbo")

MAX_NUM_TOKENS = 300

index = 1
with open("benchmarks/benchmark_set_reach_safety") as in_file:
    for line in in_file.readlines():
        yml_file = line.strip()
        if not os.path.isfile(yml_file):
            continue
        else:
            base_dir = dirname(yml_file)
            data = utils.load_yaml_file(yml_file)
            #print(f"currently processing {yml_file}")
            code_path = join(base_dir, data["input_files"])
            source_code = open(code_path).read().strip()
            if len(source_code.split()) > MAX_NUM_TOKENS * 5:
                continue
            #print(f"Processing {code_path}")
            #print(len(source_code.split()))
            #print("=============== Old  =================")
            #print(source_code)
            #print("=============== New  =================")
            r = Rewriter(code_path, source_code)
            #print(r.new_code)
            if len(r.new_code.split()) > MAX_NUM_TOKENS:
                continue
            num_tokens = len(enc.encode(r.new_code))
            with open(f"./modified_code/{data['input_files']}", 'w') as out_file:
                out_file.write(r.new_code)
            if num_tokens <= MAX_NUM_TOKENS:
                print(f"{index},{yml_file},{num_tokens}")
                source_code = open(code_path).read().strip()
                r = Rewriter(code_path, source_code, False)
                num_loops = r.find_all_loops()
                if num_loops > 2:
                    with open("many_loops.txt", 'a') as out_file:
                        out_file.write(data["input_files"] + "\n")

                programs = r.find_all_assertions()
                for i, program in enumerate(programs):
                    name = data['input_files'][:-2] + f"_{i}" + data['input_files'][-2:]
                    yml_name = os.path.basename(yml_file)[:-4] + f"_{i}" + ".yml"
                    new_data = copy(data)
                    new_data["input_files"] = name
                    with open(f"/home/haozewu/GPT_MC/benchmarks/short_single_assertion/c/{yml_name}", 'w') as f:
                        yaml.dump(new_data, f)
                    with open(f"/home/haozewu/GPT_MC/benchmarks/short_single_assertion/c/{name}", 'w') as out_file:
                        out_file.write(program)

                index += 1
