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
assume(x + y == n && z == y - x);
while (z > 0) {
assume(x + y == n && z == y - x);
x++;
z--;
}
assert(y + z == n);
while (y > 0) {
y--;
z++;
}
return 0;
}