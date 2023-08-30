void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int main() {
ARR_SIZE = (signed long long)__VERIFIER_nondet_short();
assume(ARR_SIZE > 0);
int array[ARR_SIZE][ARR_SIZE];
int row = 0, column = 0, num = -1;
signed long long sum = 0;
int temp;
short index1, index2;
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
array[row][column] = 0;
}
}
while (1) {
index1 = __VERIFIER_nondet_short();
index2 = __VERIFIER_nondet_short();
assume(index1 >= 0 && index1 < ARR_SIZE);
assume(index2 >= 0 && index2 < ARR_SIZE);
array[index1][index2] = (index1 > index2) ? (num * num * num * num) : array[index1][index2];
temp = __VERIFIER_nondet_int();
if (temp == 0) {
break;
}
}
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
sum = sum + array[row][column];
}
}
assert(2 * sum <= ARR_SIZE * (ARR_SIZE - 1));
return 0;
}