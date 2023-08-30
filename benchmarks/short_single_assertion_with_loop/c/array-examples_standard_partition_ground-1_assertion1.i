void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int aa[100000];
int a = 0;
int b = 0;
int c = 0;
int bb[100000];
int cc[100000];
while (a < 100000) {
aa[a] = __VERIFIER_nondet_int();
if (aa[a] >= 0) {
bb[b] = aa[a];
b = b + 1;
}
a = a + 1;
}
a = 0;
while (a < 100000) {
if (aa[a] >= 0) {
cc[c] = aa[a];
c = c + 1;
}
a = a + 1;
}
int x;
for (x = 0; x < b; x++) {
}
for (x = 0; x < c; x++) {
assert(cc[x] < 0);
}
return 0;
}