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
long long *c = malloc(sizeof(long long) * N);
a[0] = 6;
b[0] = 1;
c[0] = 0;
for (i = 1; i < N; i++) {
a[i] = a[i - 1] + 6;
}
for (i = 1; i < N; i++) {
b[i] = b[i - 1] + a[i - 1];
}
for (i = 1; i < N; i++) {
c[i] = c[i - 1] + b[i - 1];
}
for (i = 0; i < N; i++) {
assert(c[i] == i * i);
}
return 1;
}