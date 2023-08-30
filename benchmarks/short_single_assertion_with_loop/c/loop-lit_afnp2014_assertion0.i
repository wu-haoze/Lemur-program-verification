void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int x = 1;
int y = 0;
while (y < 1000 && __VERIFIER_nondet_int()) {
x = x + y;
y = y + 1;
}
assert(x >= y);
return 0;
}