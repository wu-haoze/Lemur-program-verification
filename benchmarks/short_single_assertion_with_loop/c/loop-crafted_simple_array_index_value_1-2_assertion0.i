void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int __VERIFIER_nondet_uint();
int main() {
unsigned int array[10000];
unsigned int index = 0;
unsigned int tmp = 0;
while (1) {
index = __VERIFIER_nondet_uint();
if (index >= 10000) {
break;
}
array[index] = index;
tmp = index;
}
assert(tmp < 10000 && array[tmp] == tmp);
}