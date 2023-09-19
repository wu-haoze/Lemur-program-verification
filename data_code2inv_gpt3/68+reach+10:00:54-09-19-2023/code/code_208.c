void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, y;
int x = 1;
while (x <= n) {
assert(x <= n && (y == n - x || y < 0));
y = n - x;
x = x + 1;
}
if (n > 0) {
}
}