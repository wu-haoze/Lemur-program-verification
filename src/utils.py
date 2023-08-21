import datetime

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
    parser.add_argument("--prop", type=str, default="reach", choices=["term", "reach"], help="Property type term/reach.")
    parser.add_argument("--learn", action="store_true",help="Use GPT?")
    parser.add_argument("-w", "--working-dir", type=str, default="./data/", help="Working directory")
    return parser.parse_args()

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

def run_subprocess(command):
    process = subprocess.Popen(
        command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True,
        bufsize=1,  # Line buffered (output line by line)
        shell=True  # Use shell to allow using command with pipes and redirections
    )

    # Loop to read and print the output line by line in real-time
    for line in process.stdout:
        print(line, end='')

    # Make sure to capture any remaining output
    for line in process.stderr:
        print(line, end='')

    # Wait for the process to finish
    process.wait()

def run_subprocess_and_get_output(command):
    p = subprocess.run( command.split(), capture_output=True )
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