void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i, j = 10, n = __VERIFIER_nondet_uint(), sn = 0;
if (n == 2147483647) {
return 0;
}
for (i = 1; i <= n; i++) {
if (i < j) {
sn = sn + (2);
}
j--;
}
assert(sn == ((long long)n) * (2) || sn == 0);
}