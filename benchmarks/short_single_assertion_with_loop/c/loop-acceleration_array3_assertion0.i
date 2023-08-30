void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
int A[1024];
int i;
for (i = 0; i < 1024; i++) {
A[i] = __VERIFIER_nondet_int();
}
for (i = 0; A[i] != 0; i++) {
if (i >= 1024) {
break;
}
}
assert(i <= 1024);
}