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
sum[0] = 0;
for (i = 0; i < N; i++) {
a[i] = 1;
}
for (i = 0; i < N; i++) {
if (a[i] == 1) {
a[i] = a[i] + 5;
} else {
a[i] = a[i] - 1;
}
}
for (i = 0; i < N; i++) {
if (a[i] == 6) {
sum[0] = sum[0] + a[i];
} else {
sum[0] = sum[0] * a[i];
}
}
assert(sum[0] == 6 * N);
return 1;
}