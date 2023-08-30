extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
void reach_error() {
  __assert_fail("0", "zero_sum_const1.c", 3, "reach_error");
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
}
extern long __VERIFIER_nondet_long(void);
void *malloc(unsigned int size);

long SIZE;

const int MAX = 100000;

int main() {
  SIZE = 2;//__VERIFIER_nondet_long();
  if (SIZE > 1 && SIZE < MAX) {
    int i;
    long *a = malloc(sizeof(long) * SIZE);
    long sum = 0;

    for (i = 0; i < SIZE; i++) {
      a[i] = 1;
    }

    for (i = 0; i < SIZE; i++) {
      sum = sum + a[i];
    }
    //assume_abort_if_not(sum == SIZE && a[0] == 1);
    for (i = 0; i < SIZE; i++) {
      //__VERIFIER_assert(sum == SIZE - i && a[i] == 1);
      //for (i = 0; i < SIZE; i++) {
      //assume_abort_if_not(sum <= SIZE - i);
      //assume_abort_if_not(a[i] == 1);
      sum = sum - a[i];
      //assume_abort_if_not(sum <= SIZE - i + 1);
      //assume_abort_if_not(sum >= SIZE - i - 1);
    }
    __VERIFIER_assert(sum == 1);
  }
  return 1;
}
