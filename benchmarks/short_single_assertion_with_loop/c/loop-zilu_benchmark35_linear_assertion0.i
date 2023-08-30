void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
if (!(x >= 0)) {
return 0;
}
while ((x >= 0) && (x < 10)) {
x = x + 1;
}
assert(x >= 10);
return 0;
}