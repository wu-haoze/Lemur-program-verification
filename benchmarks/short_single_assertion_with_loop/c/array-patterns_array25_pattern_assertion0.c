void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int main() {
ARR_SIZE = (signed long long)__VERIFIER_nondet_short();
assume(ARR_SIZE > 1);
int array[ARR_SIZE][ARR_SIZE];
int row = 0, column = 0, num = -1;
signed long sum = 0;
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
if (row % 2 == 0 && column % 2 == 0) {
array[row][column] = num * num;
} else if (row % 2 == 1 && column % 2 == 1) {
array[row][column] = num;
} else {
array[row][column] = 0;
}
}
}
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
sum = sum + array[row][column];
}
}
assert(sum == 0 || sum == ARR_SIZE);
return 0;
}