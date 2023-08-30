void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
void printEven(int i) {
}
void printOdd(int i) {
assert((i % 2) != 0);
}
int main() {
int array[100000];
int i;
int num = __VERIFIER_nondet_int();
for (i = 0; i < num; i++) {
array[i] = __VERIFIER_nondet_int();
}
for (i = 0; i < num; i++) {
if (array[i] % 2 == 0) {
printEven(array[i]);
}
}
for (i = 0; i < num; i++) {
if (array[i] % 2 != 0) {
printOdd(array[i]);
}
}
return 0;
}