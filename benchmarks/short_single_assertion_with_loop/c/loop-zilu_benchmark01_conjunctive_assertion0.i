void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
if (!(x == 1 && y == 1)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
x = x + y;
y = x;
}
assert(y >= 1);
return 0;
}