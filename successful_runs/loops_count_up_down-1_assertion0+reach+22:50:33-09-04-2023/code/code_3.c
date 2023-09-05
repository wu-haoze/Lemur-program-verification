void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
unsigned int __VERIFIER_nondet_uint();
int main() {
unsigned int n = __VERIFIER_nondet_uint();
unsigned int x = n, y = 0;
assume(x + y == n);
while (x > 0) {
assert(x + y == n);
x--;
y++;
}
}