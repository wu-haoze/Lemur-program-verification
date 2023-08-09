/* 
Geometric Series
computes x = sum(z^k)[k=0..k-1], y = z^(k-1)
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "geo2-ll.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        {reach_error();}
    }
    return;
}


int main() {
    int z, k;
    long long x, y, c;
    z = __VERIFIER_nondet_int();
    assume_abort_if_not(z>=0 && z<=5);
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k>=0 && k<=5);

    x = 1;
    y = 1;
    c = 1;

    while (1) {
        __VERIFIER_assert(1 + x*z - x - z*y == 0);

        if (!(c < k))
            break;

        c = c + 1;
        x = x * z + 1;
        y = y * z;
    }
    {}
    return 0;
}