void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int i = 0;
int k = 0;
assert(k >= 0 && k <= i);
while (i < 1000000) {
int j = __VERIFIER_nondet_int();
if (!(1 <= j && j < 1000000)) {
return 0;
}
i = i + j;
k++;
}
return 0;
}