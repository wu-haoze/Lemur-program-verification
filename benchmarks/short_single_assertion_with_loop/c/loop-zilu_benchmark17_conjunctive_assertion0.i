void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int k = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
if (!(i == 0 && k == 0)) {
return 0;
}
while (i < n) {
i++;
k++;
}
assert(k >= n);
return 0;
}