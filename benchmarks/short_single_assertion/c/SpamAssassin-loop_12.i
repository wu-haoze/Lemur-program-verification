extern void abort(void);

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

void reach_error() { ((void) sizeof ((0) ? 1 : 0), __extension__ ({ if (0) ; else __assert_fail ("0", "assert.h", 3, __extension__ __PRETTY_FUNCTION__); })); }
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: {reach_error();abort();}
  }
  return;
}
int __VERIFIER_nondet_int();
int main()
{
  int len;
  int i;
  int j;
  int bufsize;
  bufsize = __VERIFIER_nondet_int();
  if (bufsize < 0) return 0;
  len = __VERIFIER_nondet_int();
  int limit = bufsize - 4;
  for (i = 0; i < len; ) {
    for (j = 0; i < len && j < limit; ){
      if (i + 1 < len){
 {}                         
 {}                      
 if( __VERIFIER_nondet_int() ) goto ELSE;
        {}                       
 {}                      
        {}                           
 {}                      
        j++;
        i++;
        {}                       
 {}                      
        {}                           
 {}                      
        j++;
        i++;
        {}                           
 {}                      
        j++;
      } else {
ELSE:
        __VERIFIER_assert(i<len);
 {}                      
        {}                           
 {}                      
        j++;
        i++;
      }
    }
  }
  return 0;
}