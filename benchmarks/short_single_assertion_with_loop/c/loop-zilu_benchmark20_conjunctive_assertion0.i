void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
int sum = __VERIFIER_nondet_int();
if (!(i == 0 && n >= 0 && n <= 100 && sum == 0)) {
return 0;
}
while (i < n) {
sum = sum + i;
i++;
}
assert(sum >= 0);
return 0;
}