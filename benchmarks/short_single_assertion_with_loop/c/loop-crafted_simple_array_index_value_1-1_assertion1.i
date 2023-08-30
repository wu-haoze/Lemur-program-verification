void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int array[1000];
unsigned int index;
for (index = 0; index < 1000; index++) {
array[index] = (index % 2);
}
for (index = 0; index < 1000; index++) {
if (index % 2 == 0) {
} else {
assert(array[index] != 0);
}
}
}