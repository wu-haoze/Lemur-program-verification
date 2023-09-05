void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
void *malloc(unsigned int size);
long SIZE;
const int MAX = 100000;
int main() {
SIZE = __VERIFIER_nondet_long();
if (SIZE > 1 && SIZE < MAX) {
int i;
long *a = malloc(sizeof(long) * SIZE);
long sum = 0;
for (i = 0; i < SIZE; i++) {
a[i] = 1;
}
for (i = 0; i < SIZE; i++) {
sum = sum + a[i];
}
for (i = 0; i < SIZE; i++) {
assume(sum == SIZE - i && a[i] == 1);
sum = sum - a[i];
}
assert(sum == 0);
}
return 1;
}