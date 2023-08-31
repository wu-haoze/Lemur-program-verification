void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int N;
int main() {
N = __VERIFIER_nondet_int();
if (N > 0) {
int i, k;
int a[N];
i = 0;
k = 0;
while (i < N) {
a[k] = k;
i = i + 1;
k = k + 1;
}
i = 0;
while (i < N) {
assert(a[i] == i);
i = i + 1;
}
}
return 0;
}