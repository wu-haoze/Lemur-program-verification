void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int r;
double a, x;
a = __VERIFIER_nondet_double();
x = a / 2.0;
r = 0;
while (counter++ < 100) {
if (!(x > r)) {
break;
}
x = x - r;
r = r + 1;
}
assert((int)(r * r - a - r + 2 * x) == 0);
return 0;
}