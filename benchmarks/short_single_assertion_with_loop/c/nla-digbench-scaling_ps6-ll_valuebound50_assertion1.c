void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
short k;
long long y, x, c;
k = __VERIFIER_nondet_short();
assume(k >= 0 && k <= 50);
assume(k <= 256);
y = 0;
x = 0;
c = 0;
while (1) {
if (!(c < k)) {
break;
}
c = c + 1;
y = y + 1;
x = y * y * y * y * y + x;
}
assert(-2 * y * y * y * y * y * y - 6 * y * y * y * y * y - 5 * y * y * y * y + y * y + 12 * x == 0);
return 0;
}