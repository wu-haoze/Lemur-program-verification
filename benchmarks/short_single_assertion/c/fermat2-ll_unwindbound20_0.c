/* program computing a divisor for factorisation, by Bressoud */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "fermat2-ll.c", 5, "reach_error"); }
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

int counter = 0;
int main() {
    int A, R;
    long long u, v, r;
    A = __VERIFIER_nondet_int();
    R = __VERIFIER_nondet_int();
    //assume_abort_if_not(A >= 1);
    assume_abort_if_not(((long long) R - 1) * ((long long) R - 1) < A);
    //assume_abort_if_not(A <= R * R);
    assume_abort_if_not(A % 2 == 1);

    u = ((long long) 2 * R) + 1;
    v = 1;
    r = ((long long) R * R) - A;

    while (counter++<20) {
        __VERIFIER_assert(4*(A+r) == u*u - v*v - 2*u + 2*v);
        if (!(r != 0)) break;

        if (r > 0) {
            r = r - v;
            v = v + 2;
        } else {
            r = r + u;
            u = u + 2;
        }
    }

    //return  (u - v) / 2;
    {}                                                             
    return 0;
}