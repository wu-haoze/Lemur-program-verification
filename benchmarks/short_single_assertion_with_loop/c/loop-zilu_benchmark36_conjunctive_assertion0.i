void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
if (!(x == y && y == 0)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
x++;
y++;
}
assert(x == y && x >= 0);
return 0;
}