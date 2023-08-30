void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int i, j;
i = __VERIFIER_nondet_int();
j = __VERIFIER_nondet_int();
if (!(i >= 0 && i <= 1000000)) {
return 0;
}
if (!(j >= 0)) {
return 0;
}
int x = i;
int y = j;
int z = 0;
while (x != 0) {
x--;
y -= 2;
z++;
}
if (i == j) {
assert(y == -z);
}
return 0;
}