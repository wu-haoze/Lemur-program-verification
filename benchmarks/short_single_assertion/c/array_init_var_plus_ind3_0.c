extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "array_init_var_plus_ind3.c", 3, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }
extern int __VERIFIER_nondet_int();
int N = 100000;
int main()
{
  int i;
  int j=0;
  int a[N];

  for(i=0;i<N;i++){
    int x=__VERIFIER_nondet_int();
    if(x) break;
    a[i]=j;
    j=j-i;
  }

  for(int k=4;k<i;k++)
    {}
  return 0;
}