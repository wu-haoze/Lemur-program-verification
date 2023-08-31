void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int __VERIFIER_nondet_uint();
unsigned int SIZE;
const unsigned int MAX = 100000;
int linear_search(int *a, int n, int q) {
unsigned int j = 0;
while (j < n && a[j] != q) {
j++;
}
if (j < SIZE) {
return 1;
} else {
return 0;
}
}
int main() {
SIZE = (__VERIFIER_nondet_uint() / 8) + 1;
if (SIZE > 1 && SIZE < MAX) {
int *a = calloc(SIZE, sizeof(int));
a[SIZE / 2] = 3;
assert(linear_search(a, SIZE, 3));
}
}