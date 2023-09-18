void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int c = 0;
assume(n > 0);
while (unknown()) {
assume((c > 0) && (c <= n));
if (c == n) {
c = 1;
} else {
c = c + 1;
}
}
if (c == n) {
assert(c >= 0);
}
}