void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int i, n = __VERIFIER_nondet_uint();
unsigned long long sn = 0;
assume(n < 4294967296U);
for (i = 0; i <= n; i++) {
sn = sn + i;
}
unsigned long long nl = n;
unsigned long long gauss = (nl * (nl + 1U)) / 2U;
assert(sn == gauss || sn == 0);
}