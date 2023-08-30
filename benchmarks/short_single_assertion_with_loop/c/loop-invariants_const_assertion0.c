void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int s = 0;
while (__VERIFIER_nondet_uint()) {
if (s != 0) {
++s;
}
if (__VERIFIER_nondet_uint()) {
assert(s == 0);
}
}
return 0;
}