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

array_access = 0
index = 1
for filename in os.listdir("./benchmarks/code2inv/"):
    if filename[-2:] != ".c":
        continue
    full_filename = "./benchmarks/code2inv/" + filename
    yml_file =  filename[:-1] + "yml"
    yml_file_content = (f"format_version: '2.0'\n"
                        f"input_files: {filename}\n"
                        f"options:\n"
                        f"  data_model: ILP32\n"
                        f"  language: C\n"
                        f"properties:\n"
                        f"- expected_verdict: true\n"
                        f"  property_file: ../properties/unreach-call.prp\n")
    r = Rewriter(full_filename, handle_reach_error=False)
    program = Program(r.lines_to_verify, r.replacement)

    with open(f"/home/haozewu/GPT_MC/benchmarks/code2inv/c/{yml_file}", 'w') as f:
        f.write(yml_file_content)
    with open(f"/home/haozewu/GPT_MC/benchmarks/code2inv/c/{filename}", 'w') as f:
        p = program.get_program_with_assertion(program.assertions[0], [], dict(),forGPT=False)
        f.write(p)
