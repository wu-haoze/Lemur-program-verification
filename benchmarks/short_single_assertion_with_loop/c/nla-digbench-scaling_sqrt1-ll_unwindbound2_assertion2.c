void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int n;
long long a, s, t;
n = __VERIFIER_nondet_int();
a = 0;
s = 1;
t = 1;
while (counter++ < 2) {
assert(t * t - 4 * s + 2 * t + 1 == 0);
if (!(s <= n)) {
break;
}
a = a + 1;
t = t + 2;
s = s + t;
}
return 0;
}