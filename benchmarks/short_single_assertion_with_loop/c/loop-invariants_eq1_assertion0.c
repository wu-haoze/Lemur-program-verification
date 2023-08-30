void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int w = __VERIFIER_nondet_uint();
unsigned int x = w;
unsigned int y = __VERIFIER_nondet_uint();
unsigned int z = y;
while (__VERIFIER_nondet_uint()) {
if (__VERIFIER_nondet_uint()) {
++w;
++x;
} else {
--y;
--z;
}
}
assert(w == x && y == z);
return 0;
}