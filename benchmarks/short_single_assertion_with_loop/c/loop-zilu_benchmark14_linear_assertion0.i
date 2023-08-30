void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
if (!(i >= 0 && i <= 200)) {
return 0;
}
while (i > 0) {
i--;
}
assert(i >= 0);
return 0;
}