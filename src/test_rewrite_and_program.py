from program import Program, AssertionPointAttributes
from rewriter import Rewriter

def test_program_1():
    c_program = "./src/test_programs/fermat1_0.c"
    r = Rewriter(c_program)
    for i, line in enumerate(r.lines_to_verify):
        print(f"{i}: {line}")
    program = Program(r.lines_to_verify, r.replacement)
    program.dump()
    assert(program.assertion_points.keys() == {7, 8, 11, 12, 19, 20})
    assert(program.assertion_points[7] == {AssertionPointAttributes.BeforeLoop})
    assert(program.assertion_points[8] == {AssertionPointAttributes.InLoop, AssertionPointAttributes.BeforeAssertion})
    assert(program.assertion_points[11] == {AssertionPointAttributes.InLoop})
    assert(program.assertion_points[12] == {AssertionPointAttributes.InLoop})
    assert(program.assertion_points[19] == {AssertionPointAttributes.InLoop})
    assert(program.assertion_points[20] == {AssertionPointAttributes.InLoop})
