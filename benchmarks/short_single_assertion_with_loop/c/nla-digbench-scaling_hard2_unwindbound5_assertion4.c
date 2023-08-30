void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int A, B;
int r, d, p, q;
A = __VERIFIER_nondet_int();
B = 1;
r = A;
d = B;
p = 1;
q = 0;
while (counter++ < 5) {
if (!(r >= d)) {
break;
}
d = 2 * d;
p = 2 * p;
}
while (counter++ < 5) {
assert(d == B * p);
if (!(p != 1)) {
break;
}
d = d / 2;
p = p / 2;
if (r >= d) {
r = r - d;
q = q + p;
}
}
return 0;
}