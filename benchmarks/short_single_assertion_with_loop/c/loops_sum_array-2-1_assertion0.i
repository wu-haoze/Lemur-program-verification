void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int M = __VERIFIER_nondet_uint();
if (M > 1000000) {
return 0;
}
int A[M], B[M], C[M];
unsigned int i;
for (i = 0; i < M; i++) {
A[i] = __VERIFIER_nondet_int();
if (!(A[i] <= 1000000)) {
return 0;
}
}
for (i = 0; i < M; i++) {
B[i] = __VERIFIER_nondet_int();
if (!(B[i] <= 1000000)) {
return 0;
}
}
for (i = 0; i < M; i++) {
C[i] = A[i] + B[i];
}
for (i = 0; i < M; i++) {
assert(C[i] == A[i] + B[i]);
}
}