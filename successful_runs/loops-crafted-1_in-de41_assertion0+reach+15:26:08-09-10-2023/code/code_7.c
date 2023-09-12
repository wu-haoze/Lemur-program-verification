void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int n = __VERIFIER_nondet_uint();
assume(n < 1000000000);
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
assume(y + z == n && x + y == n);
while (y > 0) {
assume(y + z == n && x + y == n);
y--;
z++;
}
assert(x + y == n);
while (x > 0) {
x--;
y++;
}
return 0;
}