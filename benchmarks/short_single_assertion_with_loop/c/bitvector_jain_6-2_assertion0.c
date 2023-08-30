void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y, z;
x = 0;
y = 0;
z = 0;
while (1) {
x = x + 2 * __VERIFIER_nondet_int();
y = y + 4 * __VERIFIER_nondet_int();
z = z + 8 * __VERIFIER_nondet_int();
assert(4 * x + 2 * y + z != 4);
}
return 0;
}