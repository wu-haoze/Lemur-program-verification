void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y, z;
x = 0;
y = 0;
z = 0;
while (1) {
x = x + 1048576 * __VERIFIER_nondet_int();
y = y + 2097152 * __VERIFIER_nondet_int();
z = z + 4194304 * __VERIFIER_nondet_int();
assert(4 * x - 2 * y + z != 1048576);
}
return 0;
}