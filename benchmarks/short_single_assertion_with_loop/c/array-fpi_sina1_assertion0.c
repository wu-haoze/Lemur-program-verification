void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
void *malloc(unsigned int size);
int N;
int main() {
N = __VERIFIER_nondet_int();
if (N <= 0) {
return 1;
}
assume(N <= 2147483647 / sizeof(int));
int i;
int sum[1];
int *a = malloc(sizeof(int) * N);
sum[0] = 0;
for (i = 0; i < N; i++) {
sum[0] = sum[0] + 1;
}
for (i = 0; i < N; i++) {
a[i] = sum[0];
}
for (i = 0; i < N; i++) {
assert(a[i] == N);
}
return 1;
}