void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
unsigned A, B;
unsigned q, r, b;
A = __VERIFIER_nondet_uint();
B = 1;
q = 0;
r = A;
b = B;
while (counter++ < 2) {
if (!(r >= b)) {
break;
}
b = 2 * b;
}
while (counter++ < 2) {
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