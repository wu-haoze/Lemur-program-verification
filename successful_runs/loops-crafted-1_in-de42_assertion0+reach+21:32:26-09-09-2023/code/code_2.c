void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int n = __VERIFIER_nondet_uint();
unsigned int x = n, y = 0, z;
while (x > 0) {
x--;
y++;
}
z = y;
while (z > 0) {
x++;
z--;
}
while (y > 0) {
y--;
z++;
}
assume(x + z == 2*n );
while (x > 0) {
assume(x + z == 2*n );
x--;
z++;
}
assert(z == 2 * n);
return 0;
}