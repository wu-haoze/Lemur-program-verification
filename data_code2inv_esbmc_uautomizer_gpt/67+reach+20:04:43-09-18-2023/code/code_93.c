void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, y;
int x = 1;
assume(n > 0);
while (x <= n) {
assume(y >= -1 && y <= n-2);
y = n - x;
x = x + 1;
}
assume(y >= -1 && y <= n-2);
assert(y >= 0);
}