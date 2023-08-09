import yaml
import argparse
import subprocess

def parse_args():
    parser = argparse.ArgumentParser(description="GPT4MC.")
    parser.add_argument("input", help="Path to the yaml file.")
    parser.add_argument("-v", "--verifier", type=str, default="esbmc",
                        choices=["uautomizer", "cbmc", "esbmc", "2ls", "seahorn"],
                        help="Verifier uautomizer/cbmc/esbmc/2ls/seahorn.")
    parser.add_argument("--prop", type=str, default="reach", choices=["term", "reach"], help="Property type term/reach.")
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
