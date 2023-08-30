void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int y;
y = 1;
while (1) {
y = y + 2 * __VERIFIER_nondet_int();
assert(y != 0);
}
return 0;
}