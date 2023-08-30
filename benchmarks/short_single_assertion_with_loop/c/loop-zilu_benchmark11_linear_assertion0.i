void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
if (!(x == 0 && n > 0)) {
return 0;
}
while (x < n) {
x++;
}
assert(x == n);
return 0;
}