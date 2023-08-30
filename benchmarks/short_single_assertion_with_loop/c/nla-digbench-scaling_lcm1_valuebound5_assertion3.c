void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned a, b;
unsigned x, y, u, v;
a = __VERIFIER_nondet_uint();
assume(a >= 0 && a <= 5);
b = __VERIFIER_nondet_uint();
assume(b >= 0 && b <= 5);
assume(a >= 1);
assume(b >= 1);
assume(a <= 65535);
assume(b <= 65535);
x = a;
y = b;
u = b;
v = 0;
while (1) {
if (!(x != y)) {
break;
}
while (1) {
if (!(x > y)) {
break;
}
x = x - y;
v = v + u;
}
while (1) {
if (!(x < y)) {
break;
}
y = y - x;
u = u + v;
}
}
assert(u * y + v * y == a * b);
return 0;
}