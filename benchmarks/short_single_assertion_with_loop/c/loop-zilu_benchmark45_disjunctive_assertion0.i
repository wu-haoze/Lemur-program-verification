void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
if (!(y > 0 || x > 0)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
if (x > 0) {
x++;
} else {
y++;
}
}
assert(x > 0 || y > 0);
return 0;
}