void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int r;
double a, x, s;
a = __VERIFIER_nondet_double();
x = a;
s = 3.25;
r = 1;
while (counter++ < 10) {
if (!(x - s > 0.0)) {
break;
}
x = x - s;
s = s + 6 * r + 3;
r = r + 1;
}
assert(((4 * r * r * r - 6 * r * r + 3 * r) + (int)(4 * x - 4 * a)) == 1);
return 0;
}