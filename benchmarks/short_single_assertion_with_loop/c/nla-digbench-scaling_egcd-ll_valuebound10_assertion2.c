void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
long long a, b, p, q, r, s;
int x, y;
x = __VERIFIER_nondet_int();
assume(x >= 0 && x <= 10);
y = __VERIFIER_nondet_int();
assume(y >= 0 && y <= 10);
assume(x >= 1);
assume(y >= 1);
a = x;
b = y;
p = 1;
q = 0;
r = 0;
s = 1;
while (1) {
assert(b == x * q + y * s);
if (!(a != b)) {
break;
}
if (a > b) {
a = a - b;
p = p - q;
r = r - s;
} else {
b = b - a;
q = q - p;
s = s - r;
}
}
return 0;
}