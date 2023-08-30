void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int i, j;
i = __VERIFIER_nondet_int();
j = __VERIFIER_nondet_int();
if (!(i >= 0 && j >= 0)) {
return 0;
}
int x = i;
int y = j;
while (x != 0) {
x--;
y--;
}
if (i == j) {
assert(y == 0);
}
return 0;
}