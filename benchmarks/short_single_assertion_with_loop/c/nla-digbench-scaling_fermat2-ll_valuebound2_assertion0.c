void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int A, R;
long long u, v, r;
A = __VERIFIER_nondet_int();
assume(A >= 0 && A <= 2);
R = __VERIFIER_nondet_int();
assume(R >= 0 && R <= 2);
assume(((long long)R - 1) * ((long long)R - 1) < A);
assume(A % 2 == 1);
u = ((long long)2 * R) + 1;
v = 1;
r = ((long long)R * R) - A;
while (1) {
assert(4 * (A + r) == u * u - v * v - 2 * u + 2 * v);
if (!(r != 0)) {
break;
}
if (r > 0) {
r = r - v;
v = v + 2;
} else {
r = r + u;
u = u + 2;
}
}
return 0;
}