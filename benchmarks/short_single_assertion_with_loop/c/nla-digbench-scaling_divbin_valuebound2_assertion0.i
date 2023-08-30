void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned A, B;
unsigned q, r, b;
A = __VERIFIER_nondet_uint();
assume(A >= 0 && A <= 2);
B = __VERIFIER_nondet_uint();
assume(B >= 0 && B <= 2);
assume(B < (0x7fffffff * 2U + 1U) / 2);
assume(B >= 1);
q = 0;
r = A;
b = B;
while (1) {
if (!(r >= b)) {
break;
}
b = 2 * b;
}
while (1) {
assert(A == q * b + r);
if (!(b != B)) {
break;
}
q = 2 * q;
b = b / 2;
if (r >= b) {
q = q + 1;
r = r - b;
}
}
return 0;
}