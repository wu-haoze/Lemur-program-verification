void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }

int h = 0;

int
main()
{
  int M = 1000000000;
  int D = 9;
  int n, m, L, i;
  unsigned a0;
  unsigned b, c;
  int l;

  n = __VERIFIER_nondet_int();
  assume(n > 0 && n < 1000000);
  L = 0;
  for (m = n; m; m = m/10){
    L++;
  }
  L = L*n/D + 1;


  assume(L == 1);
  //assert(n <= 8);
  //return 1;
  a0 = 1;
  l = 1;
  while (n) {

    //assert(a0 <= M);
    //assume(a0 <= M);
    //c = 0;
    //for (i = 0; i < l || c > 0; i++) {
    b = n*a0;// + c;
    //c = b/M;
    a0 = b;// - c*M;
    //}

    //if (i > l)
    //  l = i;
    n--;
  }
  L = l;

  assert(a0 <= M);
  return 0;
}
