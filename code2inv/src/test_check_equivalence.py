from utils import check_equivalence

def test_check_equivalence():
    s1 = "x == SIZE - i"
    s2 = "x == (SIZE - i)"
    assert(check_equivalence(s1, s2))

    s1 = "x == SIZE - i"
    s2 = "x==(SIZE -i)"
    assert(check_equivalence(s1, s2))

    s1 = "x == SIZE - i"
    s2 = "x == (SIZE + i)"
    assert(not check_equivalence(s1, s2))

    s1 = "x == SIZE - i && a[i] == 1"
    s2 = "x == (SIZE - i) &&a[i]==1"
    assert(check_equivalence(s1, s2))