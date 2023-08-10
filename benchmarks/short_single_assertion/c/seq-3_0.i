extern void abort(void);

extern void __assert_fail(const char *__assertion, const char *__file,
                          unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert_perror_fail(int __errnum, const char *__file,
                                 unsigned int __line, const char *__function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void __assert(const char *__assertion, const char *__file, int __line)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
  ((void)sizeof((0) ? 1 : 0), __extension__({
     if (0)
       ;
     else
       __assert_fail("0", "assert.h", 3, __extension__ __PRETTY_FUNCTION__);
   }));
}
extern void abort(void);
void assume_abort_if_not(int cond) {
  if (!cond) {
    abort();
  }
}
void __VERIFIER_assert(int cond) {
  if (!(cond)) {
  ERROR : {
    reach_error();
    abort();
  }
  }
  return;
}
int __VERIFIER_nondet_int();
int main() {
  int n0, n1;
  int i0 = 0;
  int k = 0;
  n0 = __VERIFIER_nondet_int();
  n1 = __VERIFIER_nondet_int();
  if (!(-1000000 <= n0 && n0 < 1000000))
    return 0;
  if (!(-1000000 <= n1 && n1 < 1000000))
    return 0;
  while (i0 < n0) {
    i0++;
    k++;
  }
  int i1 = 0;
  while (i1 < n1) {
    i1++;
    k++;
  }
  int j1 = 0;
  while (j1 < n0 + n1) {
    __VERIFIER_assert(k > 0);
    j1++;
    k--;
  }
}