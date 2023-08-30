void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i, n = __VERIFIER_nondet_int(), sn = 0;
if (!(n < 1000 && n >= -1000)) {
return 0;
}
for (i = 1; i <= n; i++) {
sn = sn + (2);
}
assert(sn == n * (2) || sn == 0);
}