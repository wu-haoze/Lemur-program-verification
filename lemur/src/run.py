import os
from os.path import join, dirname, abspath
from task import Task
import utils
from verifier import Verifier
import random



PATH_DIR = abspath(os.path.dirname(__file__))
VERIFIERS = {"uautomizer": join(PATH_DIR, "../../tools/uautomizer/Ultimate.py"),
             "esbmc": join(PATH_DIR, "../../tools/esbmc/esbmc-wrapper.py")
             }

if __name__ == "__main__":
    args = utils.parse_args()

    random.seed(args.seed)

    task = Task(args.input, args.prop)

    if args.verifier != "all":
        VERIFIER = VERIFIERS[args.verifier]
        VERIFIERS = [VERIFIERS[args.verifier]]
    else:
        VERIFIERS = [VERIFIERS["esbmc"], VERIFIERS["uautomizer"]]

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
        v = Verifier(task, VERIFIERS, args)
        v.verify()
    else:
        os.chdir(dirname(VERIFIER))
        utils.run_subprocess(command, timeout=360000)
