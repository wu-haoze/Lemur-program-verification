void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int z, a, k;
long long x, y, c, az;
z = __VERIFIER_nondet_int();
assume(z >= 0 && z <= 10);
a = __VERIFIER_nondet_int();
assume(a >= 0 && a <= 10);
k = __VERIFIER_nondet_int();
assume(k >= 0 && k <= 10);
x = a;
y = 1;
c = 1;
az = (long long)a * z;
while (1) {
assert(z * x - x + a - az * y == 0);
if (!(c < k)) {
break;
}
c = c + 1;
x = x * z + a;
y = y * z;
}
return x;
}