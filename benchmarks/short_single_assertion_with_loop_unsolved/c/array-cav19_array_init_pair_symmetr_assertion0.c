void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int N = 100000;
int main() {
int i;
int a[N];
int b[N];
int c[N];
for (i = 0; i < N; i++) {
int x = __VERIFIER_nondet_int();
assume(x > -100000 && x < 100000);
a[i] = x;
b[i] = -x;
}
for (i = 0; i < N; i++) {
c[i] = a[i] + b[i];
}
for (i = 1; i < N; i++) {
assert(c[i] == 0);
}
return 0;
}