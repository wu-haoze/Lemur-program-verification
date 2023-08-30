void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int counter = 0;
int main() {
int z, k;
long long x, y, c;
z = __VERIFIER_nondet_int();
k = __VERIFIER_nondet_int();
assume(z >= 1);
assume(k >= 1);
x = 1;
y = z;
c = 1;
while (counter++ < 20) {
if (!(c < k)) {
break;
}
c = c + 1;
x = x * z + 1;
y = y * z;
}
x = x * (z - 1);
assert(1 + x - y == 0);
return 0;
}