void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int j = __VERIFIER_nondet_int();
int i = __VERIFIER_nondet_int();
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
int k = __VERIFIER_nondet_int();
j = 0;
if (!(x + y == k)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
if (j == i) {
x++;
y--;
} else {
y++;
x--;
}
j++;
}
assert(x + y == k);
return 0;
}