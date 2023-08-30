void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int n = __VERIFIER_nondet_uint();
unsigned int s = __VERIFIER_nondet_uint();
unsigned int d;
unsigned int m;
assume(s < 31);
d = (1 << s) - 1;
if (d > 0) {
m = n;
while (n > d) {
m = 0;
while (n > 0) {
m += n & d;
n = n >> s;
}
n = m;
}
if (m == d) {
m = 0;
}
assert(m == n % d);
}
return 0;
}