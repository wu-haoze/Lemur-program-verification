void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int c = 0;
assume(n > 0);
assert(c >= 1 && c <= n+1);
while (unknown()) {
if (c == n) {
c = 1;
} else {
c = c + 1;
}
}
if (c == n) {
}
}