void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 1;
int m = 1;
int n;
while (x < n) {
assert((m >= 1 && m <= x) && (x < n || m == 1));
if (unknown()) {
m = x;
}
x = x + 1;
}
if (n > 1) {
}
}