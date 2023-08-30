void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int X, Y;
long long x, y, v, xy, yx;
X = __VERIFIER_nondet_int();
Y = __VERIFIER_nondet_int();
v = ((long long)2 * Y) - X;
y = 0;
x = 0;
while (counter++ < 10) {
yx = (long long)Y * x;
xy = (long long)X * y;
assert(2 * yx - 2 * xy - X + (long long)2 * Y - v == 0);
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
return 0;
}