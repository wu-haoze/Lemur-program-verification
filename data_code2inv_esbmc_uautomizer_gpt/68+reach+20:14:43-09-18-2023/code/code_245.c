void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, y;
int x = 1;
while (x <= n) {
assume(y >= -1 && y <= n);
y = n - x;
x = x + 1;
}
assert(y >= -1 && y <= n);
if (n > 0) {
}
}