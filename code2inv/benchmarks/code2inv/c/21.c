void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int z1, z2, z3;
int x = 1;
int m = 1;
int n;
while (x < n) {
if (unknown()) {
m = x;
}
x = x + 1;
}
if (n > 1) {
assert(m < n);
}
}