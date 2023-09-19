void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, y;
int x = 1;
assume(n > 0);
while (x <= n) {
assume(x <= n && y == (n - x) && x > 0);
y = n - x;
x = x + 1;
}
assert(x <= n && y == (n - x) && x > 0);
}