void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int z, k;
long long x, y, c;
z = __VERIFIER_nondet_uint();
assume(z >= 0 && z <= 20);
k = __VERIFIER_nondet_uint();
assume(k >= 0 && k <= 20);
x = 1;
y = z;
c = 1;
while (1) {
assert(x * z - x - y + 1 == 0);
if (!(c < k)) {
break;
}
c = c + 1;
x = x * z + 1;
y = y * z;
}
x = x * (z - 1);
return 0;
}