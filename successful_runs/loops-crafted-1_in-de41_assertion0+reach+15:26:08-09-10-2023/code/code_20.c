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
assume(x + z == n && z <= y);
while (z > 0) {
assume(x + z == n && z <= y);
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
return 0;
}