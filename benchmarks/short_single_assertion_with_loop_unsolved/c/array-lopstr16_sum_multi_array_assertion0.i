void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
struct _S {
int n;
};
typedef struct _S S;
S a[1000000];
S b[1000000];
S c[1000000];
int main() {
int i;
for (i = 0; i < 1000000; i++) {
int v;
v = __VERIFIER_nondet_int();
a[i].n = v;
v = __VERIFIER_nondet_int();
b[i].n = v;
}
for (i = 0; i < 1000000; i++) {
c[i].n = a[i].n + b[i].n;
}
for (i = 0; i < 1000000; i++) {
assert(c[i].n == a[i].n + b[i].n);
}
return 0;
}