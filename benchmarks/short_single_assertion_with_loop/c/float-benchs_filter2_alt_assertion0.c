void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
typedef enum { FALSE = 0,
               TRUE = 1 } BOOLEAN;
BOOLEAN INIT;
float P, X;
float RANDOM_INPUT() {
float x;
x = __VERIFIER_nondet_float();
assume(x >= -10.f && x <= 10.f);
return x;
}
void filter2() {
static float E[2], S[2];
if (INIT) {
S[0] = X;
P = X;
E[0] = X;
} else {
P = (((((0.4677826f * X) -
        (E[0] * 0.7700725f)) +
       (E[1] * 0.4344376f)) +
      (S[0] * 1.5419f)) -
     (S[1] * 0.6740477f));
assert(P >= -15.f && P <= 15.f);
}
E[1] = E[0];
E[0] = X;
S[1] = S[0];
S[0] = P;
}
int main() {
X = RANDOM_INPUT();
INIT = TRUE;
while (TRUE) {
X = RANDOM_INPUT();
filter2();
INIT = FALSE;
}
return 0;
}