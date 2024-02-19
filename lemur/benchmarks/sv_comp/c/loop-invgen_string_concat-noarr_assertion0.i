void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main(void) {
int i, j;
L0:
i = 0;
L1:
while (__VERIFIER_nondet_int() && i < 1000000) {
i++;
}
if (i >= 100) {
STUCK:
goto STUCK;
}
j = 0;
L2:
while (__VERIFIER_nondet_int() && i < 1000000) {
i++;
j++;
}
if (j >= 100) {
goto STUCK;
}
assert(i < 200);
return 0;
}