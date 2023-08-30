void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
unsigned int i = 0;
int x = 0, y = 0;
int n = __VERIFIER_nondet_int();
if (!(n > 0)) {
return 0;
}
for (i = 0; 1; i++) {
}
assert(x != 0);
}