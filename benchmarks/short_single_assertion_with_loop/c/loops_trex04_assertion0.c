void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
void foo() {
int y = 0;
_Bool c1 = __VERIFIER_nondet_bool(), c2 = __VERIFIER_nondet_bool();
if (c1) {
y++;
}
if (c2) {
y--;
} else {
y += 10;
}
}
int main() {
int d = 1;
int x = __VERIFIER_nondet_int();
if (!(x <= 1000000 && x >= -1000000)) {
return 0;
}
_Bool c1 = __VERIFIER_nondet_bool(), c2 = __VERIFIER_nondet_bool();
if (c1) {
d = d - 1;
}
if (c2) {
foo();
}
c1 = __VERIFIER_nondet_bool(), c2 = __VERIFIER_nondet_bool();
if (c1) {
foo();
}
if (c2) {
d = d - 1;
}
while (x > 0) {
x = x - d;
}
assert(x <= 0);
}