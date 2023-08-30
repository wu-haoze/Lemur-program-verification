void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
if (!(x < y)) {
return 0;
}
while (x < y) {
if ((x < 0 && y < 0)) {
x = x + 7;
y = y - 10;
}
if ((x < 0 && y >= 0)) {
x = x + 7;
y = y + 3;
} else {
x = x + 10;
y = y + 3;
}
}
assert(x >= y && x <= y + 16);
return 0;
}