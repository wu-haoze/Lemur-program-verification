void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y;
long long a, b, p, q, r, s, c, k, xy, yy;
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
c = 0;
k = 0;
xy = (long long)x * y;
yy = (long long)y * y;
assume(xy < 2147483647);
assume(yy < 2147483647);
while (1) {
if (!(b != 0)) {
break;
}
c = a;
k = 0;
while (1) {
assert(q * xy + s * yy - q * x - b * y - s * y + b == 0);
if (!(c >= b)) {
break;
}
c = c - b;
k = k + 1;
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
return a;
}