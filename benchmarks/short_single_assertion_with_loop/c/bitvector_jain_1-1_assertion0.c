void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int y;
y = 1U;
while (1) {
y = y + 2U * __VERIFIER_nondet_uint();
assert(y != 0U);
}
return 0;
}