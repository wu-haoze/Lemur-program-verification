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
int *a = malloc(sizeof(int) * N);
for (i = 0; i < N; i++) {
if (i % 1 == 0) {
a[i] = 1;
} else {
a[i] = 0;
}
}
for (i = 0; i < N; i++) {
if (i == 0) {
sum[0] = N / 2 + 10;
} else {
sum[0] = sum[0] + a[i];
}
}
assert(sum[0] <= N);
return 1;
}