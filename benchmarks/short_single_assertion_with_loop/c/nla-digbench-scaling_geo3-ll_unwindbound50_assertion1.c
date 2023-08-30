void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int z, a, k;
long long x, y, c, az;
z = __VERIFIER_nondet_int();
a = __VERIFIER_nondet_int();
k = __VERIFIER_nondet_int();
x = a;
y = 1;
c = 1;
az = (long long)a * z;
while (counter++ < 50) {
if (!(c < k)) {
break;
}
c = c + 1;
x = x * z + a;
y = y * z;
}
assert(z * x - x + a - az * y == 0);
return x;
}