void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int x, y;
x = -50;
y = __VERIFIER_nondet_int();
if (!(-1000 < y && y < 1000000)) {
return 0;
}
while (x < 0) {
x = x + y;
y++;
}
assert(y > 0);
return 0;
}