void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
short a;
long long n, x, y, z;
a = __VERIFIER_nondet_ushort();
assume(a >= 0 && a <= 5);
n = 0;
x = 0;
y = 1;
z = 6;
while (1) {
if (!(n <= a)) {
break;
}
n = n + 1;
x = x + y;
y = y + z;
z = z + 6;
}
assert(2 * y * y - 3 * x * z - 18 * x - 10 * y + 3 * z - 10 == 0);
return 0;
}