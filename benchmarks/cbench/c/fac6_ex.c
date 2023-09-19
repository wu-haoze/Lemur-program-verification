#include "stdio.h"


int
main()
{
  int M = 1000000000;
  int D = 9;
  int n, m, L, i;
  n = 12;


  L = 0;
  for (m = n; m; m = m/10){
    L++;
  }
  L = L*n/D + 1;

  //assume(n > 0);
  //assume(L == 1);

  unsigned a0;

  unsigned b, c;
  int l;

  a0 = 1;
  l = 1;
  while (n) {
    c = 0;
    for (i = 0; i < l || c > 0; i++) {
      b = n*a0 + c;
      c = b/M;
      a0 = b - c*M;
    }
    if (i > l)
      l = i;
    n--;
    printf("%u\n", a0);
  }
  L = l;

  printf("%u\n", a0);
  return 0;
}
