void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int v = __VERIFIER_nondet_uint();
unsigned int v1;
unsigned int v2;
char parity1;
char parity2;
v1 = v;
parity1 = (char)0;
while (v1 != 0) {
if (parity1 == (char)0) {
parity1 = (char)1;
} else {
parity1 = (char)0;
}
v1 = v1 & (v1 - 1U);
}
v2 = v;
parity2 = (char)0;
v2 = v2 ^ (v2 >> 1u);
v2 = v2 ^ (v2 >> 2u);
v2 = (v2 & 286331153U) * 286331153U;
if (((v2 >> 28u) & 1u) == 0) {
parity2 = (char)0;
} else {
parity2 = (char)1;
}
assert(parity1 == parity2);
return 0;
}