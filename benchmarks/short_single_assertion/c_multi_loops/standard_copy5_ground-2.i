extern void abort(void);

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

void reach_error() { ((void) sizeof ((0) ? 1 : 0), __extension__ ({ if (0) ; else __assert_fail ("0", "standard_copy5_ground-2.c", 3, __extension__ __PRETTY_FUNCTION__); })); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }
extern int __VERIFIER_nondet_int();
int main( ) {
  int a1[100000];
  int a2[100000];
  int a3[100000];
  int a4[100000];
  int a5[100000];
  int a6[100000];

  int i;
  for ( i = 0 ; i < 100000 ; i++ ) {
    a1[i] = __VERIFIER_nondet_int();
    a5[i] = __VERIFIER_nondet_int();
    a2[i] = a1[i];
    a3[i] = a2[i];
    a4[i] = a3[i];
    a6[i] = a4[i];
    a6[i] = a5[i];
    __VERIFIER_assert( a1[i] == a6[i] );
  }
  return 0;
}
