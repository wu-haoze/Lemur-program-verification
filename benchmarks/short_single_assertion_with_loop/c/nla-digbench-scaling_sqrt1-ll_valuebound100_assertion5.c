void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
long long a, s, t;
n = __VERIFIER_nondet_int();
assume(n >= 0 && n <= 100);
a = 0;
s = 1;
t = 1;
while (1) {
if (!(s <= n)) {
break;
}
a = a + 1;
t = t + 2;
s = s + t;
}
assert(t * t - 4 * s + 2 * t + 1 == 0);
return 0;
}