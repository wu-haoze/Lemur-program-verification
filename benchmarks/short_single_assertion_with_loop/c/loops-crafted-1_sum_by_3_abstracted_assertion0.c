void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int SIZE = 20000001;
unsigned int __VERIFIER_nondet_uint();
int main() {
unsigned int n, i, k;
n = __VERIFIER_nondet_uint();
if (!(n <= SIZE)) {
return 0;
}
i = 0;
if (i < n) {
i = __VERIFIER_nondet_uint();
if (!(i < n)) {
abort();
}
if (i < n) {
i = i + 1;
}
if (i < n) {
abort();
}
}
int j = i;
while (j < n) {
j = j + 1;
}
k = j;
while (k < n) {
k = k + 1;
}
assert((i + j + k) / 3 <= SIZE);
return 0;
}