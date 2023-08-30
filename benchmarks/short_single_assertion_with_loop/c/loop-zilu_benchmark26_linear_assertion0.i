void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
if (!(x < y)) {
return 0;
}
while (x < y) {
x = x + 1;
}
assert(x == y);
return 0;
}