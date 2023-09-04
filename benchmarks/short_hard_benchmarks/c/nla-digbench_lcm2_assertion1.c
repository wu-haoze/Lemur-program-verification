void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned a, b;
unsigned x, y, u, v;
a = __VERIFIER_nondet_uint();
b = __VERIFIER_nondet_uint();
assume(a >= 1);
assume(b >= 1);
assume(a <= 65535);
assume(b <= 65535);
x = a;
y = b;
u = b;
v = a;
while (1) {
if (!(x != y)) {
break;
}
if (x > y) {
x = x - y;
v = v + u;
} else {
y = y - x;
u = u + v;
}
}
assert(x * u + y * v == 2 * a * b);
return 0;
}