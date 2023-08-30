void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int N = 1000;
int main() {
int i, j = 0, k = 0, a[N];
int lim = __VERIFIER_nondet_int();
unsigned int R = __VERIFIER_nondet_uint();
assume(R > 1 && R < 6);
assume(0 < lim && lim < N / R);
for (i = 0; i < N; i++) {
a[i] = i + 1;
if (i > N / R && k < lim) {
a[i] = i % R;
}
if (a[i] == 0) {
k++;
}
}
for (i = 0; i < N; i++) {
if (a[i] == 0) {
j++;
}
assert(j <= ((N * (R - 1)) / (R * R)));
}
return 0;
}