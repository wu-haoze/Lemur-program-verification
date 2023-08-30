void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
if (!(x == 1 || x == 2)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
if (x == 1) {
x = 2;
} else if (x == 2) {
x = 1;
}
}
assert(x <= 8);
return 0;
}