void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int N = 100000;
int a[N];
int b[N];
int c[N];
for (i = 0; i < N; i++) {
a[i] = 1;
b[i] = 2;
}
for (i = 0; i < N; i++) {
c[i] = a[i] + b[i];
}
for (i = 1; i < N; i++) {
assert(c[i] >= 3);
}
return 0;
}