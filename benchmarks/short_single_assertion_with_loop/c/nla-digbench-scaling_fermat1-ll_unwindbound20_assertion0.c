void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int A, R;
long long u, v, r;
A = __VERIFIER_nondet_int();
R = __VERIFIER_nondet_int();
assume((((long long)R - 1) * ((long long)R - 1)) < A);
assume(A % 2 == 1);
u = ((long long)2 * R) + 1;
v = 1;
r = ((long long)R * R) - A;
while (counter++ < 20) {
assert(4 * (A + r) == u * u - v * v - 2 * u + 2 * v);
if (!(r != 0)) {
break;
}
while (counter++ < 20) {
if (!(r > 0)) {
break;
}
r = r - v;
v = v + 2;
}
while (counter++ < 20) {
if (!(r < 0)) {
break;
}
r = r + u;
u = u + 2;
}
}
return 0;
}