void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
int A[1024];
int i;
for (i = 0; i < 1024 - 1; i++) {
A[i] = __VERIFIER_nondet_int();
}
A[1024 - 1] = 0;
for (i = 0; A[i] != 0; i++) {
}
assert(i <= 1024);
}