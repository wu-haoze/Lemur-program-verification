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
assume(x + z == n && y == n);
while (z > 0) {
assume(x + z == n && y == n);
x++;
z--;
}
assert(y + z == n && x == n);
while (y > 0) {
y--;
z++;
}
while (x > 0) {
x--;
y++;
}
while (z > 0) {
y--;
z--;
}
return 0;
}