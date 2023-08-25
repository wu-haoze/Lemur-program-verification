
class Predicate:
    def __init__(self, content: str, line_number: int):
        self.content = content
        self.line_number = line_number

    def __eq__(self, obj):
        return isinstance(obj, Predicate) and obj.content == self.content and obj.line_number == self.line_number