void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main(int argc, char *argv[]) {
int n, l, r, i, j;
n = __VERIFIER_nondet_int();
if (!(1 <= n && n <= 1000000)) {
return 0;
}
l = n / 2 + 1;
r = n;
if (l > 1) {
l--;
} else {
r--;
}
while (r > 1) {
i = l;
j = 2 * l;
while (j <= r) {
if (j < r) {
if (__VERIFIER_nondet_int()) {
j = j + 1;
}
}
assert(j <= n);
if (__VERIFIER_nondet_int()) {
break;
}
i = j;
j = 2 * j;
}
if (l > 1) {
l--;
} else {
r--;
}
}
return 0;
}