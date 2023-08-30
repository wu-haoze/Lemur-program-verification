void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
long gcd_test(long a, long b) {
if (a < 0) {
a = -a;
}
if (b < 0) {
b = -b;
}
if (a == 0) {
return b;
}
while (b != 0) {
if (a > b) {
a = a - b;
} else {
b = b - a;
}
}
return a;
}
int main1() {
long x;
long y;
long g;
x = 63;
y = 18;
g = gcd_test(x, y);
assert(g == 9);
return 0;
}
float f(float x) {
return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}
float fp(float x) {
return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}
int main2() {
float IN = __VERIFIER_nondet_float();
assume(IN > -2.0f && IN < 2.0f);
float x = IN - f(IN) / fp(IN);
if (!(x < 0.1)) {
reach_error();
}
return 0;
}
int main() {
if (__VERIFIER_nondet_int()) {
main1();
} else {
main2();
}
}