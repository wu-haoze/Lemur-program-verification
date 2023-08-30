void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, a, s, t;
n = __VERIFIER_nondet_int();
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
assert(t == 2 * a + 1);
return 0;
}