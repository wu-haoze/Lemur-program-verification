void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j = __VERIFIER_nondet_int();
assume(j < 10000 && j > -10000);
int k = 0;
int N = __VERIFIER_nondet_int();
assume(N < 10000 && N > -10000);
int a[N + 1];
int b[N];
for (i = 0; i < N; i++) {
assume(a[i] < 10000 && a[i] > -10000);
if (j > a[i]) {
j = a[i];
}
}
for (i = 0; i < N; i++) {
b[i] = a[i] - j;
}
for (i = 0; i < N; i++) {
k = k + b[i] + i;
}
assert(k >= 0);
return 0;
}