void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
while (x < 0x0fffffff) {
x += 2;
}
assert(x % 2);
}