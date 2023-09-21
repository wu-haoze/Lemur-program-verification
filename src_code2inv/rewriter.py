from typing import Dict

import utils
import re
import gloal_configurations as GC
import os


class Rewriter:
    """
    Class for remove comments
    remove VERIFIER_nondet_*
    """
    def __init__(self, filename: str, rewrite=True, handle_reach_error=False):
        self.code = open(filename).read().strip()
        self.new_code = self.code

        if rewrite:
            self.remove_comments()
            self.remove_re_pattern(r'__attribute__\s*\(\(.*?\)\)')

            self.remove_function("void reach_error")
            self.remove_function("void __VERIFIER_assert")
            self.remove_function("void assert")
            self.remove_function("void assume_abort_if_not")
            self.remove_function("void assume")
            self.remove_externs()

            self.new_code = self.new_code.replace("__VERIFIER_assert", "assert")
            self.new_code = self.new_code.replace("assume_abort_if_not", "assume")
            self.clang_format()
            self.remove_empty_lines()
            self.has_reach_error = False
            if handle_reach_error:
                self.replace_reach_error_with_assertion()

            self.lines_to_verify = self.new_code.split("\n")

            self.remove_verifier_nondet()

            self.lines_for_gpt = self.new_code.split("\n")

            self.replacement: Dict[str, str] = {}
            assert(len(self.lines_for_gpt) == len(self.lines_to_verify))
            for i in range(len(self.lines_to_verify)):
                if self.lines_to_verify[i] != self.lines_for_gpt[i]:
                    self.replacement[self.lines_to_verify[i]] = self.lines_for_gpt[i]

    def find_all_loops(self):
        with open("tmp.c", 'w') as out_file:
            out_file.write(self.new_code)
        command = f"clang -cc1 -ast-dump tmp.c"
        output, err = utils.run_subprocess_and_get_output(command)
        num_loops = output.count("ForStmt") + output.count("WhileStmt") + \
            output.count("DoStmt")
        return num_loops

    def remove_re_pattern(self, pattern):
        self.new_code = re.sub(pattern, '', self.new_code)

    def remove_function(self, func_name: str):
        c_code = self.new_code
        function_index = c_code.find(func_name)

        if function_index == -1:
            return None
        open_brackets = 0
        close_brackets = 0
        block_start = None

        # Find the block that defines the function
        for i in range(function_index, len(c_code)):
            if c_code[i] == '{':
                if open_brackets == 0:
                    block_start = i
                open_brackets += 1
            elif c_code[i] == '}':
                close_brackets += 1

                if open_brackets == close_brackets:
                    break
        self.new_code = c_code[: function_index] + c_code[i + 1: ]
        return


    def nondet_type(self, type_str : str):
        if type_str == "uchar":
            return "(unsigned char)"
        elif type_str == "char":
            return "(signed char)"
        elif type_str == "uint":
            return "(unsigned int)"
        else:
            return f"({type_str})"

    def get_tokens_with_verifier_nondet(self, input_string):
        pattern = r'\b__VERIFIER_nondet_\w+\b'
        tokens = set(re.findall(pattern, input_string))
        return tokens

    def remove_verifier_nondet(self):
        tokens = self.get_tokens_with_verifier_nondet(self.new_code)
        #print("Found nodet tokens", tokens)
        for token in tokens:
            pattern = token + "()"
            replacement = self.nondet_type(token.split("__VERIFIER_nondet_")[1]) + " rand()"
            self.new_code = self.new_code.replace(pattern, replacement)

    def remove_externs(self):
        pattern = r'\bextern\s+.*?;'
        functions = re.findall(pattern, self.new_code, re.MULTILINE | re.DOTALL)
        for function in functions:
            self.new_code = self.new_code.replace(function, "")
        self.new_code = self.new_code.strip()
        lines = self.new_code.split("\n")
        new_lines = []
        for line in lines:
            if line.strip()[:13] == "__extension__":
                new_lines.append(line[13:])
            else:
                new_lines.append(line)
        self.new_code = "\n".join(new_lines)

    def clang_format(self):
        with open("tmp.c", 'w') as out_file:
            out_file.write(self.new_code)
        command = f"clang-format-15 --style=file:{GC.PATH_TO_CLANG_FORMAT} ./tmp.c"
        output, err = utils.run_subprocess_and_get_output(command)
        os.remove("tmp.c")
        self.new_code = output

    def remove_empty_lines(self):
        lines = self.new_code.split("\n")
        new_lines = []
        for line in lines:
            if line == "":
                continue
            else:
                new_lines.append(line)
        self.new_code = "\n".join(new_lines)


    def remove_comments(self):
        self.clang_format()

        with open("tmp.c", 'w') as out_file:
            out_file.write(self.new_code)
        # remove comments
        command = "gcc -fpreprocessed -dD -E tmp.c"
        output, err = utils.run_subprocess_and_get_output(command)
        self.new_code = output

        lines = self.new_code.split("\n")
        new_lines = []
        for line in lines:
            if line.strip()[:2] == "//":
                continue
            elif line.strip()[:1] == "#":
                continue
            else:
                new_lines.append(line)
        self.new_code = "\n".join(new_lines)


    def replace_reach_error_with_assertion(self):
        c_code = self.new_code
        indices_object = re.finditer(pattern='reach_error', string=c_code)
        indices = [index.start() for index in indices_object]
        indices.reverse()

        replacements = []
        for function_index in indices:
            self.has_reach_error = True
            assertion_start = None
            assertion_end = None
            block_end = None
            # Find the block that defines the function
            for i in range(function_index, 0, -1):
                if c_code[i] == ')' and assertion_end is None:
                    assertion_end = i
                if c_code[i:i + 3] == "if ":
                    assert(assertion_start is None and assertion_end is not None)
                    assertion_start = i + 3
                    break

            for i in range(function_index, len(c_code)):
                if c_code[i] == '}':
                    block_end = i
            condition = c_code[assertion_start: assertion_end + 1]
            condition = f"assert(!{condition});"
            c_code = c_code[:assertion_start - 3] + condition + c_code[block_end + 1:]

        self.new_code = c_code