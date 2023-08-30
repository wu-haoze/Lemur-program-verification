void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int A, B;
int r, d, p, q;
A = __VERIFIER_nondet_int();
assume(A >= 0 && A <= 20);
B = 1;
r = A;
d = B;
p = 1;
q = 0;
while (1) {
assert(q == 0);
if (!(r >= d)) {
break;
}
d = 2 * d;
p = 2 * p;
}
while (1) {
if (!(p != 1)) {
break;
}
d = d / 2;
p = p / 2;
if (r >= d) {
r = r - d;
q = q + p;
}
}
return 0;
}