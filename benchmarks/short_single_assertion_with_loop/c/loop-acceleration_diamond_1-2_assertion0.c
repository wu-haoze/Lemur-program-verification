void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
unsigned int y = __VERIFIER_nondet_uint();
while (x < 99) {
if (y % 2 == 0) {
x++;
} else {
x += 2;
}
}
assert((x % 2) == (y % 2));
}