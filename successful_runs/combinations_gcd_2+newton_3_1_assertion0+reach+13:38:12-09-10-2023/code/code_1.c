void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
signed char x = __VERIFIER_nondet_char();
signed char y = __VERIFIER_nondet_char();
if (y > (signed char)0) {
signed char a = x;
signed char b = y;
signed char t;
if (a < 0) {
a = -a;
}
if (b < 0) {
b = -b;
}
assume(t > a || t == a);
while (b != 0) {
assume(t > a || t == a);
t = b;
b = a % b;
a = t;
}
assert(y >= a);
}
return 0;
}