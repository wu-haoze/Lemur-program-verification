void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int X, Y;
int v, x, y;
X = __VERIFIER_nondet_int();
Y = __VERIFIER_nondet_int();
v = 2 * Y - X;
y = 0;
x = 0;
while (1) {
assert(2 * Y * x - 2 * X * y - X + 2 * Y - v == 0);
if (!(x <= X)) {
break;
}
if (v < 0) {
v = v + 2 * Y;
} else {
v = v + 2 * (Y - X);
y++;
}
x++;
}
return 0;
}