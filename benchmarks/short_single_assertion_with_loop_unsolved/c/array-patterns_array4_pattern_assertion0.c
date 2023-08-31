void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
signed long long ARR_SIZE;
int main() {
ARR_SIZE = __VERIFIER_nondet_short();
assume(ARR_SIZE > 0);
int array1[ARR_SIZE];
int array2[ARR_SIZE];
int count = 0, num = -1;
signed long long sum = 0;
int temp;
short index1, index2;
for (count = 0; count < ARR_SIZE; count++) {
array1[count] = 0;
array2[count] = 0;
}
count = 1;
while (1) {
index1 = __VERIFIER_nondet_short();
index2 = __VERIFIER_nondet_short();
assume(index1 >= 0 && index1 < ARR_SIZE);
assume(index2 >= 0 && index2 < ARR_SIZE);
assume(array1[index1] == 0);
assume(array2[index2] == 0);
array1[index1] = num * (num * count);
array2[index2] = num * count;
if (count == 200) {
count = 0;
}
count++;
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