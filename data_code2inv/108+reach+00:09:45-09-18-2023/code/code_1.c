void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a, c, m, j, k;
assume(a <= m);
j = 0;
k = 0;
while (k < c) {
assume(a <= m && k >= 0);
if (m < a) {
m = a;
}
k = k + 1;
}
assert(a <= m);
}