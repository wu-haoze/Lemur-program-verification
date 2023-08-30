void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
void *malloc(unsigned int size);
int SIZE;
const int MAX = 100000;
int main() {
SIZE = __VERIFIER_nondet_int();
if (SIZE > 1 && SIZE < MAX) {
long long i;
long long *a = malloc(sizeof(long long) * SIZE);
for (i = 0; i < SIZE; i++) {
a[i] = i * i + 2;
}
for (i = 0; i < SIZE; i++) {
a[i] = a[i] - 2;
}
for (i = 0; i < SIZE; i++) {
assert(a[i] == i * i);
}
}
return 1;
}