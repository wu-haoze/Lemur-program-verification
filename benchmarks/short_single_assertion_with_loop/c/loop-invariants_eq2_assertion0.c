void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int w = __VERIFIER_nondet_uint();
unsigned int x = w;
unsigned int y = w + 1;
unsigned int z = x + 1;
while (__VERIFIER_nondet_uint()) {
y++;
z++;
}
assert(y == z);
return 0;
}