import os
from os.path import join, dirname, abspath
from task import Task
import utils
import rewritter

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

    r = rewritter.Rewritter(task.source_code, open(task.source_code).read(), False)
    r.find_all_assertions()
    #print(r.new_code)

    os.chdir(dirname(VERIFIER))
    if args.verifier == "cbmc":
        command = f"{VERIFIER} --propertyfile {task.property} --{task.arch.split('bit')[0]} {task.source_code}"
    if args.verifier == "2ls":
        command = f"{VERIFIER} --propertyfile {task.property} --{task.arch.split('bit')[0]} {task.source_code}"
    if args.verifier == "esbmc":
        command = f"python3 -u {VERIFIER} -p {task.property} -s kinduction --arch {task.arch.split('bit')[0]} {task.source_code}"
    elif args.verifier == "uautomizer":
        command = f"python3 -u {VERIFIER} --spec {task.property} --file {task.source_code} --architecture {task.arch} --full-output"

    print(command)
    utils.run_subprocess(command)
