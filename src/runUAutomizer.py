import os
from os.path import join, dirname, abspath
from task import Task
import utils

PATH_DIR = abspath(os.path.dirname(__file__))
VERIFIER = join(PATH_DIR, "../UAutomizer-linux/Ultimate.py")
SV_BENCHMARK_DIR = join(PATH_DIR, "../sv-benchmarks-main/")
print(VERIFIER, SV_BENCHMARK_DIR)

if __name__ == "__main__":
    args = utils.parse_args()
    task = Task(args.input, args.prop, SV_BENCHMARK_DIR)
    command = f"{VERIFIER} --spec {task.property} --file {task.source_code} --architecture {task.arch}"
    utils.run_subprocess(command)
