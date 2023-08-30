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
while (counter++ < 1) {
if (!(q <= n)) {
break;
}
q = 4 * q;
}
while (counter++ < 1) {
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
assert(h * h * p - 4 * h * n + 4 * n * p + 4 * h * r - 4 * p * r - p == 0);
return 0;
}