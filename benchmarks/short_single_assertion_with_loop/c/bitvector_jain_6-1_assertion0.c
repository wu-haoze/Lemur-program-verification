void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x, y, z;
x = 0U;
y = 0U;
z = 0U;
while (1) {
x = x + 2U * __VERIFIER_nondet_uint();
y = y + 4U * __VERIFIER_nondet_uint();
z = z + 8U * __VERIFIER_nondet_uint();
assert(4U * x + 2U * y + z != 4U);
}
return 0;
}