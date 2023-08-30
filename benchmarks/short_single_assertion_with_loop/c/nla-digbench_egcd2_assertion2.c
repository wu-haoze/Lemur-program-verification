void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y;
int a, b, p, q, r, s, c, k;
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
c = 0;
k = 0;
while (1) {
if (!(b != 0)) {
break;
}
c = a;
k = 0;
while (1) {
assert(b == x * q + y * s);
if (!(c >= b)) {
break;
}
c = c - b;
k = k + 1;
}
a = b;
b = c;
int temp;
temp = p;
p = q;
q = temp - q * k;
temp = r;
r = s;
s = temp - s * k;
}
return a;
}