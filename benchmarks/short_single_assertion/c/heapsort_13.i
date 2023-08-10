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
int main( int argc, char *argv[]){
  int n,l,r,i,j;
  n = __VERIFIER_nondet_int();
  if (!(1 <= n && n <= 1000000)) return 0;
  l = n/2 + 1;
  r = n;
  if(l>1) {
    l--;
  } else {
    r--;
  }
  while(r > 1) {
    i = l;
    j = 2*l;
    while(j <= r) {
      if( j < r) {
 {}                        
 {}                        
 {}                          
 {}                          
 if( __VERIFIER_nondet_int() )
   j = j + 1;
      }
      {}                        
      {}                        
      if( __VERIFIER_nondet_int() ) {
       break;
      }
      {}                        
      {}                        
      {}                        
      {}                        
      i = j;
      j = 2*j;
    }
    if(l > 1) {
      {}                        
      {}                        
      l--;
    } else {
      {}                        
      __VERIFIER_assert(r <= n);
      r--;
    }
  }
  return 0;
}