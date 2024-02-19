void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a, b;
int x, y, z;
a = __VERIFIER_nondet_double();
b = __VERIFIER_nondet_double();
assume(b >= 1);
x = a;
y = b;
z = 0;
while (1) {
assert(z + x * y == a * b);
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
return 0;
}