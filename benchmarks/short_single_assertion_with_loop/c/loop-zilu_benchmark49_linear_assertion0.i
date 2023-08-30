void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int j = __VERIFIER_nondet_int();
int r = __VERIFIER_nondet_int();
if (!(r > i + j)) {
return 0;
}
while (i > 0) {
i = i - 1;
j = j + 1;
}
assert(r > i + j);
return 0;
}