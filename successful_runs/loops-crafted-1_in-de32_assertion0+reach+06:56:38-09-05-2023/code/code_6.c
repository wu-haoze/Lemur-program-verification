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
assume(z + x == n);
while (z > 0) {
assume(z + x == n);
x++;
z--;
}
assert(x == y);
while (y > 0) {
x--;
y--;
}
return 0;
}