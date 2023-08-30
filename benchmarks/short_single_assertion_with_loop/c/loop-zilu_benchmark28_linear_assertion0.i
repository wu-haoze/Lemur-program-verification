void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int j = __VERIFIER_nondet_int();
if (!(i * i < j * j)) {
return 0;
}
while (i < j) {
j = j - i;
if (j < i) {
j = j + i;
i = j - i;
j = j - i;
}
}
assert(j == i);
return 0;
}