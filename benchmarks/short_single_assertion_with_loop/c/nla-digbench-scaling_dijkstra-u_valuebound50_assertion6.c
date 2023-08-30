void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int n, p, q, r, h;
n = __VERIFIER_nondet_uint();
assume(n >= 0 && n <= 50);
assume(n < 4294967295 / 4);
p = 0;
q = 1;
r = n;
h = 0;
while (1) {
if (!(q <= n)) {
break;
}
q = 4 * q;
}
while (1) {
if (!(q != 1)) {
break;
}
q = q / 4;
h = p + q;
p = p / 2;
if (r >= h) {
p = p + q;
r = r - h;
}
}
assert(h * h * h - 12 * h * n + 16 * n * p + 12 * h * r - 16 * p * r - h - 4 * p == 0);
return 0;
}