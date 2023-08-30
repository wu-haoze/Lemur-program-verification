void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
unsigned short N = __VERIFIER_nondet_ushort();
while (x < N) {
x += 2;
}
assert(!(x % 2));
}