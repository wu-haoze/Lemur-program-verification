int __return_main;
void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
void reach_error() {
  __assert_fail("0", "gsv2008.c.i.v+cfa-reducer.c", 4, "reach_error");
}
void abort(void);
void assume_abort_if_not(int cond) {
  if (!cond) {
    abort();
  }
}
void __VERIFIER_assert(int cond);
int __VERIFIER_nondet_int();
int main();
int __return_65;
int main() {
  int main__x;
  int main__y;
  main__x = -50;
  main__y = __VERIFIER_nondet_int();
  if (!(-1000 < main__y)) {
    return __return_main;
  } else {
    if (!(main__y < 1000000)) {
      return __return_main;
    } else {
    label_50:;
      if (main__x < 0) {
        main__x = main__x + main__y;
        int main____CPAchecker_TMP_0 = main__y;
        main__y = main__y + 1;
        goto label_50;
      } else {
        {
          int __tmp_1;
          __tmp_1 = main__y > 0;
          int {}                      
          __VERIFIER_assert__cond = __tmp_1;
          if ({}                                                           }
            return __return_main;
          } else {
            __return_65 = 0;
            return __return_65;
          }
        }
      }
    }
  }
}