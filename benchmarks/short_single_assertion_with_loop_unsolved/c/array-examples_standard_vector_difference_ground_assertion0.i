void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a[100000];
int b[100000];
int c[100000];
int i = 0;
for (i = 0; i < 100000; i++) {
a[i] = __VERIFIER_nondet_int();
b[i] = __VERIFIER_nondet_int();
}
i = 0;
while (i < 100000) {
c[i] = a[i] - b[i];
i = i + 1;
}
int x;
for (x = 0; x < 100000; x++) {
assert(c[x] == a[x] - b[x]);
}
return 0;
}