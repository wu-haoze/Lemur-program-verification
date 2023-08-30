void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int A, R;
long long u, v, r;
A = __VERIFIER_nondet_int();
assume(A >= 0 && A <= 10);
R = __VERIFIER_nondet_int();
assume(R >= 0 && R <= 10);
assume((((long long)R - 1) * ((long long)R - 1)) < A);
assume(A % 2 == 1);
u = ((long long)2 * R) + 1;
v = 1;
r = ((long long)R * R) - A;
while (1) {
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
assert(((long long)4 * A) == u * u - v * v - 2 * u + 2 * v);
return 0;
}