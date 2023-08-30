void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int N = 100000;
int a[3 * N + 1];
for (i = 0; i <= N; i++) {
a[3 * i] = 0;
a[3 * i + 1] = 0;
a[3 * i + 2] = 0;
}
for (i = 0; i <= 3 * N; i++) {
assert(a[i] >= 0);
}
return 0;
}