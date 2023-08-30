void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int __VERIFIER_nondet_uint();
int main() {
unsigned int array[100000];
unsigned int index1;
unsigned int index2;
unsigned int loop_entered = 0;
for (unsigned i = 0; i < 100000; ++i) {
array[i] = __VERIFIER_nondet_uint();
}
index1 = __VERIFIER_nondet_uint();
assume(index1 < 100000);
index2 = __VERIFIER_nondet_uint();
assume(index2 < 100000);
while (index1 < index2) {
assume(array[index1] == array[index2]);
assert((index1 < 100000) && (index2 < 100000));
index1++;
index2--;
loop_entered = 1;
}
if (loop_entered) {
while (index2 < index1) {
index2++;
index1--;
}
}
}