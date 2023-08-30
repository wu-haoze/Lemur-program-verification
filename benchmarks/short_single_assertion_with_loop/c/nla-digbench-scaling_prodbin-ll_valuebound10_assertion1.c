void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a, b;
long long x, y, z;
a = __VERIFIER_nondet_int();
assume(a >= 0 && a <= 10);
b = __VERIFIER_nondet_int();
assume(b >= 0 && b <= 10);
assume(b >= 1);
x = a;
y = b;
z = 0;
while (1) {
if (!(y != 0)) {
break;
}
if (y % 2 == 1) {
z = z + x;
y = y - 1;
}
x = 2 * x;
y = y / 2;
}
assert(z == (long long)a * b);
return 0;
}