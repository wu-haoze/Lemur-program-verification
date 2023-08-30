void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n = __VERIFIER_nondet_int();
int sum = __VERIFIER_nondet_int();
int i = __VERIFIER_nondet_int();
if (!(n >= 0 && sum == 0 && i == 0)) {
return 0;
}
while (i < n) {
sum = sum + i;
i++;
}
assert(sum >= 0);
return 0;
}