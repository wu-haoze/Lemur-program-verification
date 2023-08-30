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
int *a = malloc(sizeof(int) * N);
for (i = 0; i < N; i++) {
a[i] = 0;
}
for (i = 0; i < N; i++) {
if (N % 2 == 0) {
a[i] = a[i] + 2;
} else {
a[i] = a[i] + 1;
}
}
for (i = 0; i < N; i++) {
assert(a[i] % 2 == N % 2);
}
return 1;
}