void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int main() {
ARR_SIZE = (signed long long)__VERIFIER_nondet_short();
assume(ARR_SIZE > 0);
int array1[ARR_SIZE];
int array2[ARR_SIZE];
int count = 0, num = -1;
short index;
int temp;
signed long long sum = 0;
for (count = 0; count < ARR_SIZE; count++) {
array1[count] = 0;
array2[count] = 0;
}
while (1) {
index = __VERIFIER_nondet_short();
assume(index >= 0 && index < ARR_SIZE);
array1[index] = array1[index] + (num * num * index);
array2[ARR_SIZE - 1 - index] = array2[ARR_SIZE - 1 - index] + (num * index);
temp = __VERIFIER_nondet_int();
if (temp == 0) {
break;
}
}
for (count = 0; count < ARR_SIZE; count++) {
sum = sum + array1[count] + array2[count];
}
assert(sum == 0);
return 0;
}