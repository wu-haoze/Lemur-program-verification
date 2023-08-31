void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int n = 100000;
int pos;
int element = __VERIFIER_nondet_int();
int found = 0;
int vectorx[n];
for (i = 0; i < n; i++) {
vectorx[i] = __VERIFIER_nondet_int();
}
for (i = 0; i < n && !found; i++) {
if (vectorx[i] == element) {
found = 1;
pos = i;
}
}
if (found) {
for (i = pos; i < n - 1; i++) {
vectorx[i] = vectorx[i + 1];
}
}
if (found) {
int x;
for (x = 0; x < pos; x++) {
assert(vectorx[x] != element);
}
}
return 0;
}