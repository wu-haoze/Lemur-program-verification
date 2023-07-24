import os
from os.path import join, dirname, abspath
from task import Task
import utils

PATH_DIR = abspath(os.path.dirname(__file__))
VERIFIERS = {"uautomizer": join(PATH_DIR, "../uautomizer/Ultimate.py"),
             "cbmc": join(PATH_DIR, "../cbmc/cbmc")}
SV_BENCHMARK_DIR = join(PATH_DIR, "../sv-benchmarks-main/")

if __name__ == "__main__":
    args = utils.parse_args()
    task = Task(args.input, args.prop, SV_BENCHMARK_DIR)

    VERIFIER = VERIFIERS[args.verifier]

    working_dir = join(PATH_DIR, f"../{args.verifier}")
    os.chdir(working_dir)
    if args.verifier == "cbmc":
        command = f"{VERIFIER} --propertyfile {task.property} --{task.arch.split('bit')[0]} {task.source_code}"
    elif args.verifier == "uautomizer":
        command = f"{VERIFIER} --spec {task.property} --file {task.source_code} --architecture {task.arch}"

    utils.run_subprocess(command)
