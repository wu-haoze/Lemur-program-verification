void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n = __VERIFIER_nondet_int();
int i = __VERIFIER_nondet_int();
int l = __VERIFIER_nondet_int();
i = l;
if (!(l > 0)) {
return 0;
}
while (i < n) {
i++;
}
assert(l >= 1);
return 0;
}