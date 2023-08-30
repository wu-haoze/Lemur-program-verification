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
long long sum[1];
long long *a = malloc(sizeof(long long) * N);
int *b = malloc(sizeof(int) * N);
sum[0] = 0;
for (i = 0; i < N; i++) {
a[i] = 1;
}
for (i = 0; i < N; i++) {
b[i] = 1;
}
for (i = 0; i < N; i++) {
sum[0] = sum[0] + a[i];
}
for (i = 0; i < N; i++) {
a[i] = b[i] + sum[0];
}
for (i = 0; i < N; i++) {
assert(a[i] == N + 1);
}
return 1;
}