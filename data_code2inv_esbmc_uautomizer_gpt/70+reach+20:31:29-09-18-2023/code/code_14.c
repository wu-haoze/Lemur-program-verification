void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n, v1, v2, v3;
int x = 1;
int y;
while (x <= n) {
assume(y >= -1 && y <= n-1);
y = n - x;
x = x + 1;
}
if (n > 0) {
assert(y < n);
}
}