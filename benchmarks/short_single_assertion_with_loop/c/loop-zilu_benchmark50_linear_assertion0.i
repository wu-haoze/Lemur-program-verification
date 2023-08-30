void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int xa = __VERIFIER_nondet_int();
int ya = __VERIFIER_nondet_int();
if (!(xa + ya > 0)) {
return 0;
}
while (xa > 0) {
xa--;
ya++;
}
assert(ya >= 0);
return 0;
}