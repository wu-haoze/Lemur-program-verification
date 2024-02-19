void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int i, n = __VERIFIER_nondet_uint(), sn = 0;
for (i = 0; i <= n; i++) {
sn = sn + i;
}
assert(sn == (n * (n + 1)) / 2 || sn == 0);
}
