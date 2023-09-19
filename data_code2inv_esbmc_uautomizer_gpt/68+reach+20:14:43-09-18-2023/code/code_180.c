void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, y;
int x = 1;
while (x <= n) {
assume(y + x == n + 2);
y = n - x;
x = x + 1;
}
assume(y + x == n + 2);
if (n > 0) {
assert(y <= n);
}
}