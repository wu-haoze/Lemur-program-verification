void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int n0, n1;
int i0 = 0;
int k = 0;
n0 = __VERIFIER_nondet_int();
n1 = __VERIFIER_nondet_int();
if (!(-1000000 <= n0 && n0 < 1000000)) {
return 0;
}
if (!(-1000000 <= n1 && n1 < 1000000)) {
return 0;
}
while (i0 < n0) {
i0++;
k++;
}
int i1 = 0;
while (i1 < n1) {
i1++;
k++;
}
int j1 = 0;
while (j1 < n0 + n1) {
assert(k > 0);
j1++;
k--;
}
}