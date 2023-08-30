void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int N = 100000;
int main() {
int i;
int j = 0;
int k = 0;
int a[N];
for (i = 0; i < N; i++) {
int x = __VERIFIER_nondet_int();
if (x) {
break;
}
a[i] = j;
j = j + i;
k = k - i;
}
for (int l = 1; l < i; l++) {
assert(a[l] >= k);
}
return 0;
}