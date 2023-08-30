void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
short a;
long long n, x, y, z;
a = __VERIFIER_nondet_ushort();
n = 0;
x = 0;
y = 1;
z = 6;
while (counter++ < 2) {
assert(x == n * n * n);
if (!(n <= a)) {
break;
}
n = n + 1;
x = x + y;
y = y + z;
z = z + 6;
}
return 0;
}