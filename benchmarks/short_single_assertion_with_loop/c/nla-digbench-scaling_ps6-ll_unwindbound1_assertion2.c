void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
short k;
long long y, x, c;
k = __VERIFIER_nondet_short();
assume(k <= 256);
y = 0;
x = 0;
c = 0;
while (counter++ < 1) {
if (!(c < k)) {
break;
}
c = c + 1;
y = y + 1;
x = y * y * y * y * y + x;
}
assert(k * y == y * y);
return 0;
}