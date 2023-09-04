void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int f(unsigned int z) {
return z + 2;
}
int main(void) {
unsigned int x = 0;
while (x < 0x0fffffff) {
x = f(x);
}
assert(x % 2);
}