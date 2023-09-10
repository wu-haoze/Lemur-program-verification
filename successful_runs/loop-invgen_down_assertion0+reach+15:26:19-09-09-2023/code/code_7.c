void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int n;
int k = 0;
int i = 0;
n = __VERIFIER_nondet_int();
while (i < n) {
i++;
k++;
}
int j = n;
assert(j == k || n == j + k);
while (j > 0) {
j--;
k--;
}
return 0;
}