void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
short SIZE;
int main() {
SIZE = __VERIFIER_nondet_short();
if (SIZE > 1) {
int i;
short a[SIZE];
long long sum = 0;
for (int i = 0; i < SIZE; i++) {
a[i] = __VERIFIER_nondet_short();
}
for (i = 0; i < SIZE; i++) {
sum = sum + a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum + a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum + a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum + a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum + a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum - a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum - a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum - a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum - a[i];
}
for (i = 0; i < SIZE; i++) {
sum = sum - a[i];
}
assert(sum == 0);
}
return 1;
}