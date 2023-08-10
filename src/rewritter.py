import utils
import re

class Rewritter:
    """
    Class for remove comments
    remove VERIFIER_nondet_*
    """
    def __init__(self, filename: str, code : str, rewrite=True):
        self.code = code.strip()
        self.new_code = self.code

        if rewrite:
            self.remove_comments()
            self.remove_re_pattern(r'__attribute__\s*\(\(.*?\)\)')


            self.remove_function("void reach_error(")
            self.remove_function("void __VERIFIER_assert(")
            self.remove_function("void assume_abort_if_not")
            self.remove_function("void assume")
            self.remove_externs()

            self.new_code = self.new_code.replace("__VERIFIER_assert", "assert")
            self.remove_verifier_nondet()
            self.clang_format()
            self.remove_empty_lines()
            #self.replace_reach_error_with_assertion()
            #print(self.new_code)

    def find_all_assertions(self):
        substring_to_replace = []

        matches = list(re.finditer("__VERIFIER_assert", self.new_code))
        for match in matches[1:]:
            for i in range(match.start(), len(self.new_code)):
                if self.new_code[i] == ";":
                    break
            print("Assertion", match.start(), i + 1)
            print(self.new_code[match.start(): i + 1])
            substring_to_replace.append((match.start(), i + 1));

        if len(matches) == 0:
            for match in list(re.finditer("reach_error", self.new_code))[1:]:
                for i in range(match.start(), len(self.new_code)):
                    if self.new_code[i] == ";":
                        break
                print("Reach error:", match.start(), i + 1)
                print(self.new_code[match.start(): i + 1])
                substring_to_replace.append((match.start(), i + 1));

        programs = []
        for i, (start, end) in enumerate(substring_to_replace):
            program = self.new_code
            for i_, (start_, end_) in enumerate(substring_to_replace):
                if i != i_:
                    prev_len = len(program)
                    replacement = "{}" + "".join((end_ - start_ - 2) * [" "])
                    program = program[:start_] + replacement + program[end_:]
                    if len(program) != prev_len:
                        print(f"{prev_len}, {len(program)}")
                        exit(0)
            programs.append(program)
        return programs

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
        command = "clang-format --style=LLVM ./tmp.c"
        output, err = utils.run_subprocess_and_get_output(command)
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
