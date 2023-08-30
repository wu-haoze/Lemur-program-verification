void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y;
long long a, b, p, q, r, s;
x = __VERIFIER_nondet_int();
assume(x >= 0 && x <= 100);
y = __VERIFIER_nondet_int();
assume(y >= 0 && y <= 100);
assume(x >= 1);
assume(y >= 1);
a = x;
b = y;
p = 1;
q = 0;
r = 0;
s = 1;
while (1) {
if (!(b != 0)) {
break;
}
long long c, k;
c = a;
k = 0;
while (1) {
if (!(c >= b)) {
break;
}
long long d, v;
d = 1;
v = b;
while (1) {
assert(v == b * d);
if (!(c >= 2 * v)) {
break;
}
d = 2 * d;
v = 2 * v;
}
c = c - v;
k = k + d;
}
a = b;
b = c;
long long temp;
temp = p;
p = q;
q = temp - q * k;
temp = r;
r = s;
s = temp - s * k;
}
return 0;
}