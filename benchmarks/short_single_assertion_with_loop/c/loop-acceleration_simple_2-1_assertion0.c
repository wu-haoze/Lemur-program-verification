void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = __VERIFIER_nondet_uint();
while (x < 0x0fffffff) {
x++;
}
assert(x >= 0x0fffffff);
}