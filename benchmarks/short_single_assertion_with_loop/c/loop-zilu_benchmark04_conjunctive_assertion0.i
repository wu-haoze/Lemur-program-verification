void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int k = __VERIFIER_nondet_int();
int j = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
if (!(n >= 1 && k >= n && j == 0)) {
return 0;
}
while (j <= n - 1) {
j++;
k--;
}
assert(k >= 0);
return 0;
}