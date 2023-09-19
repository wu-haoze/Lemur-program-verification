void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a, m, j, k;
j = 0;
k = 0;
while (k < 1) {
assert(m >= a && k == 0);
if (m < a) {
m = a;
}
k = k + 1;
}
}