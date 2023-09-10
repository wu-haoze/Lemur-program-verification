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
assume(y + z == n && x == n);
while (y > 0) {
assert(y + z == n && x == n);
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