void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
unsigned int n, p, q, r, h;
n = __VERIFIER_nondet_uint();
assume(n < 4294967295 / 4);
p = 0;
q = 1;
r = n;
h = 0;
while (counter++ < 100) {
if (!(q <= n)) {
break;
}
q = 4 * q;
}
while (counter++ < 100) {
assert(h * h * h - 12 * h * n * q + 16 * n * p * q - h * q * q - 4 * p * q * q + 12 * h * q * r - 16 * p * q * r == 0);
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