import utils
import re
from pycparser import c_parser, c_generator, c_ast

class RewritingVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.to_remove = []

    def visit_FuncDef(self, node):
        if node.decl.name in ["__VERIFIER_assert", "reach_error", "assume_abort_if_not", "assume"]:
            self.to_remove.append(node)



class Rewritter:
    """
    Class for remove comments
    remove VERIFIER_nondet_*
    """
    def __init__(self, code : str):
        self.code = code.strip()
        self.new_code = self.code

        self.remove_verifier_nondet()
        self.remove_comments()
        self.remove_externs()
        #print(self.new_code)
        #parser = c_parser.CParser()
        #with open("test.c", 'w') as out_file:
        #    out_file.write(self.new_code)


        #ast = parser.parse(self.new_code)

        #visitor = RewritingVisitor()
        #visitor.visit(ast)
        #for node in visitor.to_remove:
        #    ast.ext.remove(node)
        #generator = c_generator.CGenerator()
        #self.new_code = generator.visit(ast)
        #self.new_code = self.new_code.replace("__VERIFIER_assert", "assert")
        #print(self.new_code)


    def nondet_type(self, type_str : str):
        if type_str == "uchar":
            return "(unsigned char)"
        elif type_str == "char":
            return "(signed char)"
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

    def remove_comments(self):
        lines = self.new_code.split("\n")
        new_lines = []
        for line in lines:
            if line.strip()[:2] == "//":
                continue
            else:
                new_lines.append(line)
        self.new_code = "\n".join(new_lines)
