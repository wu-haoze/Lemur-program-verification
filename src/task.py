import utils
from os.path import join, abspath,dirname

class Task:
    def __init__(self, yml_file, prop="unreach"):
        self.data = utils.load_yaml_file(yml_file)
        assert(prop in ["reach", "term"])

        base_dir = abspath(dirname(yml_file))
        self.source_code = join(base_dir, self.data["input_files"])
        properties = self.data["properties"]
        self.property = None
        self.answer = None
        for p in properties:
            if prop == "reach" and p["property_file"] == "../properties/unreach-call.prp":
                self.property = p["property_file"]
                self.answer = p["expected_verdict"]
                break
            elif prop == "term" and p["property_file"] == "../properties/termination.prp":
                self.property = p["property_file"]
                self.answer = p["expected_verdict"]
                break
        assert(self.property is not None and self.answer is not None)
        self.property = join(base_dir, self.property)
        assert(self.data["options"]["language"] == "C")
        if "32" in self.data["options"]["data_model"]:
            self.arch = "32bit"
        else:
            self.arch = "64bit"

    def dump(self):
        print(self.data)
