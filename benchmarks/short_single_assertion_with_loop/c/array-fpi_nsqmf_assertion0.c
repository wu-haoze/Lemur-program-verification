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
long long *a = malloc(sizeof(long long) * N);
long long *b = malloc(sizeof(long long) * N);
b[0] = 1;
a[0] = 1;
for (i = 1; i < N; i++) {
b[i] = b[i - 1] + 2;
}
for (i = 1; i < N; i++) {
a[i] = a[i - 1] + b[i - 1] + 2;
}
for (i = 0; i < N; i++) {
assert(a[i] == N + (i + 1) * (i + 1));
}
return 1;
}