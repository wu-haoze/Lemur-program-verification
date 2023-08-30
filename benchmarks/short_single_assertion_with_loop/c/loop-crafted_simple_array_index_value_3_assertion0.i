void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int array[10000];
unsigned int index = 0;
unsigned int tmp = 0;
while (index < 10000) {
array[index] = tmp;
index = index + 1;
tmp = tmp + 2;
}
for (index = 0; index < 10000; index++) {
assert((array[index] == 2 * index) || (array[index] == 0));
}
}