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
for (i = 0; i < N; i++) {
a[i] = ((i + 1) * (i + 1));
}
for (i = 0; i < N; i++) {
a[i] = a[i] - i;
}
for (i = 0; i < N; i++) {
a[i] = a[i] - i;
}
for (i = 0; i < N; i++) {
assert(a[i] == i * i);
}
return 1;
}