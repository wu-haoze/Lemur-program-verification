void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int j = __VERIFIER_nondet_int();
int k = __VERIFIER_nondet_int();
if (!(i < j && k > 0)) {
return 0;
}
while (i < j) {
k = k + 1;
i = i + 1;
}
assert(k > j - i);
return 0;
}