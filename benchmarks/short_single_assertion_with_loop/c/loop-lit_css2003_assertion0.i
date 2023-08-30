void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int i, j, k;
i = 1;
j = 1;
k = __VERIFIER_nondet_int();
if (!(0 <= k && k <= 1)) {
return 0;
}
while (i < 1000000) {
i = i + 1;
j = j + k;
k = k - 1;
assert(1 <= i + k && i + k <= 2 && i >= 1);
}
return 0;
}