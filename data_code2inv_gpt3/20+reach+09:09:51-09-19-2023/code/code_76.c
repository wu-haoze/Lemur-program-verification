void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int z1, z2, z3;
int x = 0;
int m = 0;
int n;
while (x < n) {
assume(x <= n && (m >= 0 || x == m));
if (unknown()) {
m = x;
}
x = x + 1;
}
assume(x <= n && (m >= 0 || x == m));
if (n > 0) {
assert(m >= 0);
}
}