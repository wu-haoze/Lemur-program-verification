void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int S = __VERIFIER_nondet_int();
assume(S > 1);
assume(S < 1073741823);
int i;
int a[2 * S];
int acopy[2 * S];
for (i = 0; i < S; i++) {
acopy[2 * S - (i + 1)] = a[2 * S - (i + 1)];
acopy[i] = a[i];
}
for (i = 0; i < 2 * S; i++) {
assert(acopy[i] == a[i]);
}
return 0;
}