void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
void upsweep(int *a, int left, int right) {
if (right > left + 1) {
int space = right - left;
upsweep(a, left - space / 2, left);
upsweep(a, right - space / 2, right);
}
a[right] = a[left] + a[right];
}
void downsweep(int *a, int left, int right) {
int tmp = a[right];
a[right] = a[right] + a[left];
a[left] = tmp;
if (right > left + 1) {
int space = right - left;
downsweep(a, left - space / 2, left);
downsweep(a, right - space / 2, right);
}
}
int is_pow2(unsigned int x) {
while (((x % 2) == 0) && x > 1) {
x /= 2;
}
return (x == 1);
}
void check(int *a0, int *a, int n) {
int i, sum = 0;
for (i = 0; i < n; i++) {
assert(sum == a[i]);
sum += a0[i];
}
}
int main() {
int n = __VERIFIER_nondet_int();
assume(n > 1 && n < (1 << 30));
assume(is_pow2(n));
int *a = calloc(n, sizeof(int));
int *a0 = calloc(n, sizeof(int));
int i;
for (i = 0; i < n; i++) {
a0[i] = a[i];
}
upsweep(a, n / 2 - 1, n - 1);
a[n - 1] = 0;
downsweep(a, n / 2 - 1, n - 1);
check(a0, a, n);
free(a);
free(a0);
return 0;
}