void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y;
x = 1;
y = 1;
while (1) {
x = x + 2 * __VERIFIER_nondet_int();
y = y + 2 * __VERIFIER_nondet_int();
assert(x + y != 1);
}
return 0;
}