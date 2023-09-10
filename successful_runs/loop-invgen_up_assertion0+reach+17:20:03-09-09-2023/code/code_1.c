void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int n;
int i = 0;
int k = 0;
n = __VERIFIER_nondet_int();
while (i < n) {
i++;
k++;
}
int j = 0;
assume(n == j + k);
while (j < n) {
assert(k > 0);
j++;
k--;
}
}