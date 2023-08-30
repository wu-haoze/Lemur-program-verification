void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
long long a, b, p, q, r, s;
int x, y;
x = __VERIFIER_nondet_int();
y = __VERIFIER_nondet_int();
assume(x >= 1);
assume(y >= 1);
a = x;
b = y;
p = 1;
q = 0;
r = 0;
s = 1;
while (counter++ < 10) {
assert(a == y * r + x * p);
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