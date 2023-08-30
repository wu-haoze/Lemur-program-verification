void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = __VERIFIER_nondet_uint();
unsigned int y = x + 1;
while (x < 1024) {
x++;
y++;
}
assert(x == y);
}