void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int S = __VERIFIER_nondet_int();
assume(S > 1);
long long i;
long long a[S];
for (i = 0; i < S; i++) {
a[i] = ((i - 1) * (i + 1));
}
for (i = 0; i < S; i++) {
a[i] = a[i] - (i * i);
}
for (i = 0; i < S; i++) {
assert(a[i] == -1);
}
return 0;
}