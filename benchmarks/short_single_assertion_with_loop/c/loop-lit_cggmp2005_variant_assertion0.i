void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int lo, mid, hi;
lo = 0;
mid = __VERIFIER_nondet_int();
if (!(mid > 0 && mid <= 1000000)) {
return 0;
}
hi = 2 * mid;
while (mid > 0) {
lo = lo + 1;
hi = hi - 1;
mid = mid - 1;
}
assert(lo == hi);
return 0;
}