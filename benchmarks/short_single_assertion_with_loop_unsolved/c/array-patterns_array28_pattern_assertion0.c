void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int main() {
ARR_SIZE = (signed long long)__VERIFIER_nondet_short();
assume(ARR_SIZE > 0);
int array[ARR_SIZE][ARR_SIZE];
int row = 0, column = 0, num = -1;
signed long long sum = 0;
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
if (row > column) {
array[row][column] = row + column;
} else if (row < column) {
array[row][column] = num * (row + column);
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
assert(sum == 0);
return 0;
}