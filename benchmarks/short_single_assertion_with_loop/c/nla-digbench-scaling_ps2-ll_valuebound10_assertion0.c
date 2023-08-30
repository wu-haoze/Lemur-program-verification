void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int k;
long long y, x, c;
k = __VERIFIER_nondet_int();
assume(k >= 0 && k <= 10);
y = 0;
x = 0;
c = 0;
while (1) {
assert((y * y) - 2 * x + y == 0);
if (!(c < k)) {
break;
}
c = c + 1;
y = y + 1;
x = y + x;
}
return 0;
}