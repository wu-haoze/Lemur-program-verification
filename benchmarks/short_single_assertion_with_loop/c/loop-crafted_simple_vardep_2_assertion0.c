void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int i = 0;
unsigned int j = 0;
unsigned int k = 0;
while (k < 0x0fffffff) {
i = i + 1;
j = j + 2;
k = k + 3;
assert((k == 3 * i) && (j == 2 * i));
}
}