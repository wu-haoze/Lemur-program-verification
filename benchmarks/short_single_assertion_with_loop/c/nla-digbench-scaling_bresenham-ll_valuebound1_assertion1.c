void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int X, Y;
long long x, y, v, xy, yx;
X = __VERIFIER_nondet_int();
assume(X >= 0 && X <= 1);
Y = __VERIFIER_nondet_int();
assume(Y >= 0 && Y <= 1);
v = ((long long)2 * Y) - X;
y = 0;
x = 0;
while (1) {
yx = (long long)Y * x;
xy = (long long)X * y;
if (!(x <= X)) {
break;
}
if (v < 0) {
v = v + (long long)2 * Y;
} else {
v = v + 2 * ((long long)Y - X);
y++;
}
x++;
}
xy = (long long)x * y;
yx = (long long)Y * x;
assert(2 * yx - 2 * xy - X + (long long)2 * Y - v + 2 * y == 0);
return 0;
}