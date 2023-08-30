void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int __VERIFIER_nondet_uint();
int main() {
unsigned int SIZE = __VERIFIER_nondet_uint();
if (SIZE >= 4000000000 / sizeof(int)) {
return 0;
}
int i, j, k, key;
int v[SIZE];
for (j = 0; j < SIZE; j++) {
v[j] = __VERIFIER_nondet_int();
}
for (j = 1; j < SIZE; j++) {
key = v[j];
i = j - 1;
while ((i >= 0) && (v[i] > key)) {
if (i < 2) {
v[i + 1] = v[i];
}
i = i - 1;
}
v[i + 1] = key;
}
for (k = 1; k < SIZE; k++) {
assert(v[k - 1] <= v[k]);
}
return 0;
}