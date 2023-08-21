from task import Task
from utils import create_working_dir, run_subprocess
import os
from shutil import copy
from os.path import join, basename, dirname
from rewritter import Rewritter

PATCH = 'void assert(int cond) {\n  if (!(cond)) {\n  ERROR : {\n      reach_error();\n      abort();\n    }\n  }\n}\n\nvoid assume(int cond) {\n  if (!cond) {\n    abort();\n  }\n}\n'

class Verifier:
    def  __init__(self, task: Task, verifier: str,  args):
        self.working_dir, self.prompt_dir, self.code_dir = create_working_dir(args.working_dir, task.source_code, args.prop)
        os.chdir(self.working_dir)
        self.initialize_verification(task)

        self.verifier = verifier

        self.run_verifier()



    def initialize_verification(self, task : Task):
        # copy over the c file and the property file
        self.c_program = join(self.working_dir, "base.c")
        self.property = join(self.working_dir, "property")
        self.arch = task.arch
        copy(task.source_code, self.c_program)
        copy(task.property, self.property)

        r = Rewritter(self.c_program, open(self.c_program).read().strip())
        with open(join(self.working_dir, "temp.c"), 'w') as out_file:
            out_file.write(PATCH)
            out_file.write(r.new_code)
        print(r.new_code)
        self.c_program = join(self.working_dir, "temp.c")


    def run_verifier(self):
        os.chdir(dirname(self.verifier))
        command = f"python3 -u {self.verifier} --spec {self.property} --file {self.c_program} --architecture {self.arch} --full-output"
        print(command)
        run_subprocess(command)
        os.chdir(self.working_dir)

