extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "in-de32.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
void __VERIFIER_assert(int cond) {
  if (!(cond)) {
  ERROR : {
    reach_error();
    abort();
  }
  }
  return;
}

void assume_abort_if_not(int cond) {
  if (!cond) {
    abort();
  }
}

int main() {
  unsigned int n = __VERIFIER_nondet_uint();
  unsigned int x = n, y = 0, z;
  while (x > 0) {
    //__VERIFIER_assert(x + y == n);
    x--;
    y++;
  }
  z = y;
  //__VERIFIER_assert(x == 0);
  //__VERIFIER_assert(y == n);
  //__VERIFIER_assert(z == n);
  //__VERIFIER_assert(x == 0);
  //__VERIFIER_assert(x + z == n && y == n);
  while (z > 0) {
    //__VERIFIER_assert(x + z == n && y == n);
    x++;
    z--;
  }
  //__VERIFIER_assert(z == 0);
  //__VERIFIER_assert(x + z == n);
  //__VERIFIER_assert(x == n);
  //__VERIFIER_assert(z == 0);

  //__VERIFIER_assert(z + x == y);
  while (y > 0) {
    //__VERIFIER_assert(z + x == y);
    x--;
    y--;
  }

  __VERIFIER_assert(x == 0);
  return 0;
}
