void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y;
long long q, r, a, b;
x = __VERIFIER_nondet_int();
assume(x >= 0 && x <= 5);
y = __VERIFIER_nondet_int();
assume(y >= 0 && y <= 5);
assume(y >= 1);
q = 0;
r = x;
a = 0;
b = 0;
while (1) {
if (!(r >= y)) {
break;
}
a = 1;
b = y;
while (1) {
if (!(r >= 2 * b)) {
break;
}
a = 2 * a;
b = 2 * b;
}
r = r - b;
q = q + a;
}
assert(x == q * y + r);
return 0;
}