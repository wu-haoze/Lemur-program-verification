import datetime

import pycparser
import yaml
import argparse
import subprocess
import os
from os.path import join, basename, abspath


def parse_args():
    parser = argparse.ArgumentParser(description="GPT4MC.")
    parser.add_argument("input", help="Path to the yaml file.")
    parser.add_argument("-v", "--verifier", type=str, default="esbmc",
                        choices=["uautomizer", "cbmc", "esbmc", "2ls", "seahorn"],
                        help="Verifier uautomizer/cbmc/esbmc/2ls/seahorn.")
    parser.add_argument("--prop", type=str, default="reach", choices=["term", "reach"],
                        help="Property type term/reach.")
    parser.add_argument("--learn", action="store_true", help="Use GPT?")
    parser.add_argument("-w", "--working-dir", type=str, default="./data/", help="Working directory")
    parser.add_argument("--verbosity", type=int, default=1, help="Verbosity")
    parser.add_argument("--seed", type=int, default=1, help="Seed")
    parser.add_argument("--cache", type=str, default=None, help="Use a previous working directory")
    parser.add_argument("--num-assertions", type=int, default=2, help="Number of assertions")
    parser.add_argument("--num-attempts", type=int, default=3, help="Number of attempts for GPT")
    parser.add_argument("--simulate", action="store_true", help="Simulate?")
    parser.add_argument("--per-instance-timeout", type=int, default=60, help="Per-instance timeout")

    args = parser.parse_args()
    if args.cache is not None:
        args.cache = abspath(args.cache)
    print(args)
    return args


def load_yaml_file(file_path):
    try:
        with open(file_path, "r") as file:
            data = yaml.safe_load(file)
            return data
    except FileNotFoundError:
        print(f"Error: The file '{file_path}' does not exist.")
        return None
    except yaml.YAMLError as e:
        print(f"Error: Failed to parse YAML file '{file_path}': {e}")
        return None


def run_subprocess(command, live_output: bool = True, timeout: int= 60):
    stdout = []
    stderr = []
    process = subprocess.Popen(
        f"timeout {timeout} " + command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True,
        bufsize=1,  # Line buffered (output line by line)
        shell=True  # Use shell to allow using command with pipes and redirections
    )

    # Loop to read and print the output line by line in real-time
    for line in process.stdout:
        if live_output:
            print(line, end='')
        stdout.append(line)

    # Make sure to capture any remaining output
    for line in process.stderr:
        if live_output:
            print(line, end='')
        stderr.append(line)

    # Wait for the process to finish
    process.wait()
    return stdout, stderr


def run_subprocess_and_get_output(command):
    p = subprocess.run(command.split(), capture_output=True)
    return p.stdout.decode(), p.stderr.decode()


def create_working_dir(working_dir: str, c_filename: str, property: str):
    now = datetime.datetime.now()
    date_time = now.strftime("%H:%M:%S-%m-%d-%Y")
    new_dir = join(working_dir, f"{basename(c_filename)[:-2]}+{property}+{date_time}")
    try:
        os.makedirs(new_dir)
        new_dir = abspath(new_dir)
        print(f"Working directory created: {new_dir}")
        prompt_dir = join(new_dir, "prompts/")
        code_dir = join(new_dir, "code/")
        os.mkdir(prompt_dir)
        os.mkdir(code_dir)
        return new_dir, prompt_dir, code_dir
    except:
        print(f"Unable to create working directory: {new_dir}")
        exit(1)

class color:
   PURPLE = '\033[95m'
   CYAN = '\033[96m'
   DARKCYAN = '\033[36m'
   BLUE = '\033[94m'
   GREEN = '\033[92m'
   YELLOW = '\033[93m'
   RED = '\033[91m'
   BOLD = '\033[1m'
   UNDERLINE = '\033[4m'
   END = '\033[0m'

def bold(text : str) -> str:
   return color.BOLD + text + color.END

def check_equivalence(c1, c2):
    # parse the statements into ASTs
    try:
        ast1 = pycparser.c_parser.CParser().parse("void main() {" + f"assert({c1});" + "}")
        ast2 = pycparser.c_parser.CParser().parse("void main() {" + f"assert({c2});" + "}")

        # Compare the ASTs recursively
        return compare_nodes(ast1, ast2)
    except:
        return False

def compare_nodes(node1, node2):
    # Check if both nodes are None
    if node1 is None and node2 is None:
        return True

    # Check if one node is None and the other is not
    if node1 is None or node2 is None:
        return False

    # Check if both nodes have the same class
    if type(node1) != type(node2):
        return False

    # Check if both nodes have the same attributes
    for attr in node1.attr_names:
        if getattr(node1, attr) != getattr(node2, attr):
            return False

    # Check if both nodes have the same number of children
    if len(node1.children()) != len(node2.children()):
        return False

    # Compare the children recursively
    for child1, child2 in zip(node1.children(), node2.children()):
        if not compare_nodes(child1[1], child2[1]):
            return False

    # If all checks passed, return True
    return True