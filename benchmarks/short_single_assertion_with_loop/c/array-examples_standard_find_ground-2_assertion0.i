void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a[100000];
int e = __VERIFIER_nondet_int();
for (int j = 0; j < 100000; j++) {
a[j] = __VERIFIER_nondet_int();
}
int i = 0;
while (i < 100000 && a[i] != e) {
i = i + 1;
}
int x;
for (x = 0; x < i; x++) {
assert(a[x] != e);
}
return 0;
}