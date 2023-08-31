void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int __VERIFIER_nondet_uint();
int main() {
unsigned int array[10000];
unsigned int index;
for (index = 0; index < 10000; index++) {
unsigned int tmp = __VERIFIER_nondet_uint();
assume(tmp > index);
array[index] = tmp;
}
for (index = 0; index < 10000; index++) {
assert(array[index] > index);
}
}