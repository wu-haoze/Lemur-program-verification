void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
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
v = 0;
while (counter++ < 1) {
if (!(x != y)) {
break;
}
while (counter++ < 1) {
if (!(x > y)) {
break;
}
x = x - y;
v = v + u;
}
while (counter++ < 1) {
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