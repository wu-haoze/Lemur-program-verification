void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int x, y;
long long a, b, p, q;
x = __VERIFIER_nondet_int();
y = __VERIFIER_nondet_int();
assume(y >= 1);
a = x;
b = y;
p = 1;
q = 0;
while (counter++ < 20) {
if (!(a != 0 && b != 0)) {
break;
}
if (a % 2 == 0 && b % 2 == 0) {
a = a / 2;
b = b / 2;
p = 4 * p;
} else if (a % 2 == 1 && b % 2 == 0) {
a = a - 1;
q = q + b * p;
} else if (a % 2 == 0 && b % 2 == 1) {
b = b - 1;
q = q + a * p;
} else {
a = a - 1;
b = b - 1;
q = q + (a + b + 1) * p;
}
}
assert(a * b == 0);
return 0;
}