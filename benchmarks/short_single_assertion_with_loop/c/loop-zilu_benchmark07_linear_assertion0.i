void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = __VERIFIER_nondet_int();
int n = __VERIFIER_nondet_int();
int k = __VERIFIER_nondet_int();
_Bool flag = __VERIFIER_nondet_bool();
i = 0;
if (!(n > 0 && n < 10)) {
return 0;
}
while (i < n) {
i++;
if (flag) {
k += 4000;
} else {
k += 2000;
}
}
assert(k > n);
return 0;
}