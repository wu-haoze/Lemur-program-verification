void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
unsigned int SIZE = 1;
unsigned int j, k;
int array[SIZE], menor;
menor = __VERIFIER_nondet_int();
for (j = 0; j < SIZE; j++) {
array[j] = __VERIFIER_nondet_int();
if (array[j] <= menor) {
menor = array[j];
}
}
assert(array[0] > menor);
return 0;
}