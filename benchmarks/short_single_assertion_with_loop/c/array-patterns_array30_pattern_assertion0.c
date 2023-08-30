void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int diff(short idx1, short idx2) {
if (idx1 > idx2) {
return (idx1 - idx2);
} else {
return (idx2 - idx1);
}
}
int main() {
ARR_SIZE = (signed long long)__VERIFIER_nondet_short();
assume(ARR_SIZE > 0);
int array[ARR_SIZE][ARR_SIZE];
int row = 0, column = 0;
signed long long sum = 0;
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
array[row][column] = diff(row, column);
}
}
for (row = 0; row < ARR_SIZE; row++) {
for (column = 0; column < ARR_SIZE; column++) {
sum = sum + array[row][column];
}
}
assert(3 * sum == (ARR_SIZE * (ARR_SIZE - 1) * (ARR_SIZE + 1)));
return 0;
}