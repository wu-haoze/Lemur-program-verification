void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int x, y;
long long q, r, a, b;
x = __VERIFIER_nondet_int();
y = __VERIFIER_nondet_int();
assume(y >= 1);
q = 0;
r = x;
a = 0;
b = 0;
while (counter++ < 100) {
assert(x == q * y + r);
if (!(r >= y)) {
break;
}
a = 1;
b = y;
while (counter++ < 100) {
if (!(r >= 2 * b)) {
break;
}
a = 2 * a;
b = 2 * b;
}
r = r - b;
q = q + a;
}
return 0;
}