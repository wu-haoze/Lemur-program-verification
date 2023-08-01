import tiktoken
import sys
import os
from task import Task
import utils
from os.path import dirname, join
from rewritter import Rewritter

enc = tiktoken.encoding_for_model("gpt-3.5-turbo")

MAX_NUM_TOKENS = 1000

with open("benchmarks/benchmark_set_reach_safety") as in_file:
    for line in in_file.readlines():
        yml_file = line.strip()
        if not os.path.isfile(yml_file):
            continue
        else:
            base_dir = dirname(yml_file)
            data = utils.load_yaml_file(yml_file)
            #print(f"currently processing {yml_file}")
            source_code = open(join(base_dir, data["input_files"])).read().strip()
            if len(source_code.split()) > 10 * MAX_NUM_TOKENS:
                continue
            #print("=============== Old  =================")
            #print(source_code)
            #print("=============== New  =================")
            r = Rewritter(source_code)
            #print(r.new_code)
            if len(r.new_code.split()) > MAX_NUM_TOKENS:
                continue
            if len(enc.encode(r.new_code)) <= MAX_NUM_TOKENS:
                print(f"{yml_file}")
