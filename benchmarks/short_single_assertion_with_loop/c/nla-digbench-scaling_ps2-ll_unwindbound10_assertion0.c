void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int k;
long long y, x, c;
k = __VERIFIER_nondet_int();
y = 0;
x = 0;
c = 0;
while (counter++ < 10) {
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