#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define M 1000000000
#define D 9

int h = 0;

int
calc_fac(uint32_t *a, int L, uint64_t n)
{
  uint64_t b, c;
  int i, l;

  a[0] = 1;
  for (i = 1; i < L; i++)
    a[i] = 0;
  l = 1;
  while (n) {
    c = 0;
    for (i = 0; i < l || c; i++) {
      b = n*a[i] + c;
      c = b/M;
      a[i] = b - c*M;
    }
    if (i > l)
      l = i;
    n--;
  }
  return l;
}

void
print_digits(int n, int c)
{
  int d;

  if (c <= 0)
    return;
  print_digits(n/10, c - 1);
  d = n%10;
  if (h || d) {
    putchar('0' + d);
    h = 1;
  }
}

int
main(int argc, char **argv)
{
  uint32_t *a;
  int n, m, L, i;

  if (argc != 2) {
    fprintf(stderr, "usage: %s input\n", *argv);
    exit(2);
  }
  n = atoi(argv[1]);
  if (n < 0) {
    fprintf(stderr, "%s: input is negative\n", *argv);
    exit(2);
  }
  L = 0;
  for (m = n; m; m = m/10) {
    printf("L: %u\n", L);
    L++;
  }

  L = L*n/D + 1;
  printf("L final: %u\n", L);
  a = malloc(L*sizeof(*a));
  if (!a) {
    fprintf(stderr, "%s: out of memory\n", *argv);
    exit(1);
  }
  L = calc_fac(a, L, n);
  for (i = L - 1; i >= 0; i--) {
    printf("%u\n", a[i]);
  }


  for (i = L - 1; i >= 0; i--) {
    print_digits(a[i], D);
  }
  putchar('\n');
  return 0;
}
