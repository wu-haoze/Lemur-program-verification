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
assert(h * h * p - 4 * h * n * q + 4 * n * p * q - p * q * q + 4 * h * q * r - 4 * p * q * r == 0);
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