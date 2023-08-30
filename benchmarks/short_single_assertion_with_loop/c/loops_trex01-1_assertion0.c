void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
_Bool __VERIFIER_nondet_bool();
int __VERIFIER_nondet_int();
void f(int d) {
int x = __VERIFIER_nondet_int(), y = __VERIFIER_nondet_int(), k = __VERIFIER_nondet_int(), z = 1;
if (!(k <= 1073741823)) {
return;
}
L1:
while (z < k) {
z = 2 * z;
}
assert(z >= 2);
L2:
while (x > 0 && y > 0) {
_Bool c = __VERIFIER_nondet_bool();
if (c) {
P1:
x = x - d;
y = __VERIFIER_nondet_bool();
z = z - 1;
} else {
y = y - d;
}
}
}
int main() {
_Bool c = __VERIFIER_nondet_bool();
if (c) {
f(1);
} else {
f(2);
}
return 0;
}