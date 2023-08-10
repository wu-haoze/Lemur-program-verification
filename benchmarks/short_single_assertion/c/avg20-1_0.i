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
       __assert_fail("0", "avg20-1.c", 18, __extension__ __PRETTY_FUNCTION__);
   }));
}

int avg(int x[20]) {
  int i;
  long long ret;
  ret = 0;
  for (i = 0; i < 20; i++) {
    ret = ret + x[i];
  }
  return ret / 20;
}

int main() {
  int x[20];
  int temp;
  int ret;
  int ret2;
  int ret5;

  ret = avg(x);

  temp = x[0];
  x[0] = x[1];
  x[1] = temp;
  ret2 = avg(x);
  temp = x[0];
  for (int i = 0; i < 20 - 1; i++) {
    x[i] = x[i + 1];
  }
  x[20 - 1] = temp;
  ret5 = avg(x);

  if (ret != ret2 || ret != ret5) {
    { reach_error(); }
  }
  return 1;
}