void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int m = 0;
int n;
while (x < n) {
assume((m >= 0 && m <= x) || (x == 0));
if (unknown()) {
m = x;
}
x = x + 1;
}
assume((m >= 0 && m <= x) || (x == 0));
if (n > 0) {
assert(m >= 0);
}
}