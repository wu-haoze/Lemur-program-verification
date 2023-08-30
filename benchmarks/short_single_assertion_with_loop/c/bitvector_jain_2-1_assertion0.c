void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x, y;
x = 1U;
y = 1U;
while (1) {
x = x + 2U * __VERIFIER_nondet_uint();
y = y + 2U * __VERIFIER_nondet_uint();
assert(x + y != 1U);
}
return 0;
}