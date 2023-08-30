void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int x1, x2;
int y1, y2, y3;
x1 = __VERIFIER_nondet_int();
x2 = __VERIFIER_nondet_int();
assume(x1 >= 0);
assume(x2 != 0);
y1 = 0;
y2 = 0;
y3 = x1;
while (counter++ < 2) {
if (!(y3 != 0)) {
break;
}
if (y2 + 1 == x2) {
y1 = y1 + 1;
y2 = 0;
y3 = y3 - 1;
} else {
y2 = y2 + 1;
y3 = y3 - 1;
}
}
assert(y1 * x2 + y2 == x1);
return 0;
}