void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int k = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
if (!(i == 0 && k == n && n >= 0)) {
return 0;
}
while (i < n) {
k--;
i += 2;
}
assert(2 * k >= n - 1);
return 0;
}