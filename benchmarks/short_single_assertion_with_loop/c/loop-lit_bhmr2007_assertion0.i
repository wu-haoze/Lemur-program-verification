void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int i, n, a, b;
i = 0;
a = 0;
b = 0;
n = __VERIFIER_nondet_int();
if (!(n >= 0 && n <= 1000000)) {
return 0;
}
while (i < n) {
if (__VERIFIER_nondet_int()) {
a = a + 1;
b = b + 2;
} else {
a = a + 2;
b = b + 1;
}
i = i + 1;
}
assert(a + b == 3 * n);
return 0;
}