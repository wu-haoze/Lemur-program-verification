void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 5;
while (__VERIFIER_nondet_int()) {
x += 8;
}
assert((x & 5) == 5);
return 0;
}