void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a[5];
unsigned int len = 0;
int i;
while (__VERIFIER_nondet_bool()) {
if (len == 4) {
len = 0;
}
a[len] = 0;
len++;
}
assert(len >= 0 && len < 5);
return 1;
}