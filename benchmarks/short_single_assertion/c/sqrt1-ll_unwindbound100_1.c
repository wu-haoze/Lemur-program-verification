/* Compute the floor of the square root of a natural number */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "sqrt1-ll.c", 5, "reach_error"); }
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
    int n;
    long long a, s, t;
    n = __VERIFIER_nondet_int();

    a = 0;
    s = 1;
    t = 1;

    while (counter++<100) {
        {}                              
        __VERIFIER_assert(s == (a + 1) * (a + 1));
	{}                                          
        // the above 2 should be equiv to 

        if (!(s <= n))
            break;

        a = a + 1;
        t = t + 2;
        s = s + t;
    }
    
    {}                                
    {}                                        
    {}                                          

    return 0;
}