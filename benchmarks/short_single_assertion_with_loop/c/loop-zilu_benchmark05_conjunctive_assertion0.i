void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
if (!(x >= 0 && x <= y && y < n)) {
return 0;
}
while (x < n) {
x++;
if (x > y) {
y++;
}
}
assert(y == n);
return 0;
}