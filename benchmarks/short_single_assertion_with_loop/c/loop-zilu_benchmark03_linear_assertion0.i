void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = __VERIFIER_nondet_int();
int y = __VERIFIER_nondet_int();
int i = __VERIFIER_nondet_int();
int j = __VERIFIER_nondet_int();
_Bool flag = __VERIFIER_nondet_bool();
x = 0;
y = 0;
if (!(i == 0 && j == 0)) {
return 0;
}
while (__VERIFIER_nondet_bool()) {
x++;
y++;
i += x;
j += y;
if (flag) {
j += 1;
}
}
assert(j >= i);
return 0;
}