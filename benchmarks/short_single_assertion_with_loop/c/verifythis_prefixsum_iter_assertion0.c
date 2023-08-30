void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int upsweep(int *a, int n) {
int space = 1;
for (; space < n; space = space * 2) {
int left = space - 1;
while (left < n) {
int right = left + space;
a[right] = a[left] + a[right];
left = left + space * 2;
}
}
return space;
}
void downsweep(int *a, int n, int space) {
a[n - 1] = 0;
space = space / 2;
for (; space > 0; space = space / 2) {
int right = space * 2 - 1;
while (right < n) {
int left = right - space;
int temp = a[right];
a[right] = a[left] + a[right];
a[left] = temp;
right = right + space * 2;
}
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
assume(n >= 0 && n < (1 << 30));
assume(is_pow2(n));
int *a = calloc(n, sizeof(int));
int *a0 = calloc(n, sizeof(int));
int i;
for (i = 0; i < n; i++) {
a0[i] = a[i];
}
int space = upsweep(a, n);
downsweep(a, n, space);
check(a0, a, n);
free(a);
free(a0);
return 0;
}