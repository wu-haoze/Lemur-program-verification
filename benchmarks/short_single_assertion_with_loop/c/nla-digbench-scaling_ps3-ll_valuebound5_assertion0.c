void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
short k;
long long y, x, c;
k = __VERIFIER_nondet_short();
assume(k >= 0 && k <= 5);
y = 0;
x = 0;
c = 0;
while (1) {
assert(6 * x - 2 * y * y * y - 3 * y * y - y == 0);
if (!(c < k)) {
break;
}
c = c + 1;
y = y + 1;
x = y * y + x;
}
return 0;
}