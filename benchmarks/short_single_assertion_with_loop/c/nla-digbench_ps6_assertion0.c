void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int k, y, x, c;
k = __VERIFIER_nondet_int();
y = 0;
x = 0;
c = 0;
while (1) {
assert(-2 * y * y * y * y * y * y - 6 * y * y * y * y * y - 5 * y * y * y * y + y * y + 12 * x == 0);
if (!(c < k)) {
break;
}
c = c + 1;
y = y + 1;
x = y * y * y * y * y + x;
}
return 0;
}