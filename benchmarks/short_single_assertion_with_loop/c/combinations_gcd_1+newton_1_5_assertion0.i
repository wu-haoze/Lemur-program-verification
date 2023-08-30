void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed char gcd_test(signed char a, signed char b) {
signed char t;
if (a < 0) {
a = -a;
}
if (b < 0) {
b = -b;
}
while (b != 0) {
t = b;
b = a % b;
a = t;
}
return a;
}
int main1() {
signed char x = __VERIFIER_nondet_char();
signed char y = __VERIFIER_nondet_char();
signed char g;
if (y > 0 && x % y == 0) {
g = gcd_test(x, y);
assert(g == y);
}
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
assume(IN > -1.0f && IN < 1.0f);
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