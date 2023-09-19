void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 1;
int m = 1;
int n;
while (x < n) {
assume(m >= 1 && x <= n);
if (unknown()) {
m = x;
}
x = x + 1;
}
assume(m >= 1 && x <= n);
if (n > 1) {
assert(m >= 1);
}
}