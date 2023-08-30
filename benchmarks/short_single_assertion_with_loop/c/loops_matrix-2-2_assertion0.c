void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int N_LIN = __VERIFIER_nondet_uint();
unsigned int N_COL = __VERIFIER_nondet_uint();
if (N_LIN >= 4000000000 / sizeof(int) || N_COL >= 4000000000 / sizeof(int)) {
return 0;
}
unsigned int j, k;
int matriz[N_COL][N_LIN], maior;
maior = __VERIFIER_nondet_int();
for (j = 0; j < N_COL; j++) {
for (k = 0; k < N_LIN; k++) {
matriz[j][k] = __VERIFIER_nondet_int();
if (matriz[j][k] > maior) {
maior = matriz[j][k];
}
}
}
for (j = 0; j < N_COL; j++) {
for (k = 0; k < N_LIN; k++) {
assert(matriz[j][k] < maior);
}
}
}