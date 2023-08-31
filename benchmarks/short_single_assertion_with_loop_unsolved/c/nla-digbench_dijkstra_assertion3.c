void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, p, q, r, h;
n = __VERIFIER_nondet_int();
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
assert(h * h * n - 4 * h * n * p + 4 * (n * n) * q - n * q * q - h * h * r + 4 * h * p * r - 8 * n * q * r + q * q * r + 4 * q * r * r == 0);
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
return 0;
}