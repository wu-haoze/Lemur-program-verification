void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }


int
main(int argc, char **argv)
{
  unsigned int *a;

  int M = 1000000000;
  int D = 9;
  int n, m, L, i;
  unsigned b, c;
  int l;

  n = __VERIFIER_nondet_int();
  assume(n > 0 && n < 1000000);

  //assume(n<=8);

  L = 0;
  int tmp;
  for (m = n; m; m = m/10) {
    tmp = 1;
    for (i = 0; i < L; i++)
      {
        tmp *= 10;
      }
    assert(tmp * m <= n);

    L++;
  }
  return 0;
  //assume(L == 1);

  L = L*n/D + 1;
  //assume(L == 1);

  a = malloc(L*sizeof(unsigned int));
  a[0] = 1;
  for (i = 1; i < L; i++)
    a[i] = 0;
  l = 1;

  //  assume(n <= 8);
  while (n) {
    assume(a[0] < M);
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

  //assert(a[0] == 720 * 7 * 8);
  // assert(a[0] < M);
  //if (L == 3)
  assert(a[0] < M);

  return 0;
}
