void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
struct S {
unsigned short p;
unsigned short q;
} a[10000];
int main() {
unsigned char k;
int i;
for (i = 0; i < 1000000; i++) {
a[i].p = i;
a[i].q = i;
}
for (i = 0; i < 1000000; i++) {
if (__VERIFIER_nondet_short()) {
k = __VERIFIER_nondet_short();
a[i].p = k;
a[i].q = k * k;
}
}
for (i = 0; i < 1000000; i++) {
assert(a[i].p == a[i].q || a[i].q == a[i].p * a[i].p);
}
return 0;
}