void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int z, a, k;
int x, y, c;
z = __VERIFIER_nondet_int();
a = __VERIFIER_nondet_int();
k = __VERIFIER_nondet_int();
x = a;
y = 1;
c = 1;
while (1) {
assert(z * x - x + a - a * z * y == 0);
if (!(c < k)) {
break;
}
c = c + 1;
x = x * z + a;
y = y * z;
}
return x;
}