import os
from os.path import join, dirname, abspath
from task import Task
import utils
from verifier import Verifier

PATH_DIR = abspath(os.path.dirname(__file__))
VERIFIERS = {"uautomizer": join(PATH_DIR, "../tools/uautomizer/Ultimate.py"),
             "cbmc": join(PATH_DIR, "../tools/cbmc/cbmc"),
             "2ls": join(PATH_DIR, "../tools/2ls/2ls"),
             "esbmc": join(PATH_DIR, "../tools/esbmc/esbmc-wrapper.py")
             }
SV_BENCHMARK_DIR = join(PATH_DIR, "../benchmarks/sv-benchmarks-main/")

if __name__ == "__main__":
    args = utils.parse_args()
    task = Task(args.input, args.prop)

    VERIFIER = VERIFIERS[args.verifier]

    if args.verifier == "cbmc":
        command = f"{VERIFIER} --propertyfile {task.property} --{task.arch.split('bit')[0]} {task.source_code}"
    elif args.verifier == "2ls":
        command = f"{VERIFIER} --propertyfile {task.property} --{task.arch.split('bit')[0]} {task.source_code}"
    elif args.verifier == "esbmc":
        command = f"python3 -u {VERIFIER} -p {task.property} -s kinduction --arch {task.arch.split('bit')[0]} {task.source_code}"
    elif args.verifier == "uautomizer":
        command = f"python3 -u {VERIFIER} --spec {task.property} --file {task.source_code} --architecture {task.arch} --full-output"
    else:
        command = ""
    if args.learn:
        v = Verifier(task, VERIFIER, args)
    else:
        os.chdir(dirname(VERIFIER))
        utils.run_subprocess(command)
