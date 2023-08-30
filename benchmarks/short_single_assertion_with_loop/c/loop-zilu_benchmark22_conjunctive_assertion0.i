void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
if (!(x == 1 && y == 0)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
x = x + y;
y++;
}
assert(x >= y);
return 0;
}