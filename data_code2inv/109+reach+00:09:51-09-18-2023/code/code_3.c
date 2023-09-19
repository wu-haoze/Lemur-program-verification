void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a, c, m, j, k;
j = 0;
k = 0;
while (k < c) {
assume(m >= a && m >= j);
if (m < a) {
m = a;
}
k = k + 1;
}
if (c > 0) {
assert(a <= m);
}
}