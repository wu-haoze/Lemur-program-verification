extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "test29-1.c", 3, "{} }


extern int __VERIFIER_nondet_int(void);

union dummy {
  int a;
  char b;
};

int main()
{
  union dummy d1, d2;
  int n = __VERIFIER_nondet_int();
  union dummy *pd = n ? &d1 : &d2;
  d1.a = __VERIFIER_nondet_int();
  if (pd == &d1) {
    pd->a = 0;
  } else {
    pd->b = 0;
  }
  if (pd == &d2 && d1.a != 0) {
    goto ERROR;
  }

  return 0;

  ERROR: {reach_error();abort();}
  return 1;
}