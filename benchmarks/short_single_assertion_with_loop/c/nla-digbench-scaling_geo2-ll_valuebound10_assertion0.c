void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int z, k;
long long x, y, c;
z = __VERIFIER_nondet_int();
assume(z >= 0 && z <= 10);
k = __VERIFIER_nondet_int();
assume(k >= 0 && k <= 10);
x = 1;
y = 1;
c = 1;
while (1) {
assert(1 + x * z - x - z * y == 0);
if (!(c < k)) {
break;
}
c = c + 1;
x = x * z + 1;
y = y * z;
}
return 0;
}