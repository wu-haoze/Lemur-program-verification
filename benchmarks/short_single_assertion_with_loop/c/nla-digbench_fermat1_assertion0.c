void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int A, R;
int u, v, r;
A = __VERIFIER_nondet_double();
R = __VERIFIER_nondet_double();
assume((R - 1) * (R - 1) < A);
assume(A % 2 == 1);
u = 2 * R + 1;
v = 1;
r = R * R - A;
while (1) {
assert(4 * (A + r) == u * u - v * v - 2 * u + 2 * v);
if (!(r != 0)) {
break;
}
while (1) {
if (!(r > 0)) {
break;
}
r = r - v;
v = v + 2;
}
while (1) {
if (!(r < 0)) {
break;
}
r = r + u;
u = u + 2;
}
}
return 0;
}