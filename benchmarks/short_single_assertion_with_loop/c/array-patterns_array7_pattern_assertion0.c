void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int main() {
ARR_SIZE = (signed long long)__VERIFIER_nondet_short();
assume(ARR_SIZE > 0);
int array1[ARR_SIZE];
int array2[ARR_SIZE];
int count = 0, num = -1;
signed long long sum = 0;
int temp;
signed long long index, pivot;
for (count = 0; count < ARR_SIZE; count++) {
array1[count] = num * (num * count);
array2[count] = num * count;
}
while (1) {
index = (signed long long)__VERIFIER_nondet_short();
pivot = (signed long long)__VERIFIER_nondet_short();
assume(pivot > 0);
assume(index >= pivot && index < ARR_SIZE - pivot);
array1[index] = array1[index - pivot] + array1[index + pivot];
array2[index] = array2[index - pivot] + array2[index + pivot];
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