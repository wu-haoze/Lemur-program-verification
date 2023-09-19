void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int m = 0;
int n;
while (x < n) {
assert(m < n || x >= n);
if (unknown()) {
m = x;
}
x = x + 1;
}
if (n > 0) {
}
}