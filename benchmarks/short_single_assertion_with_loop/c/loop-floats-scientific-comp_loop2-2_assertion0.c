void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
float pi = 3.14159;
int main() {
float x = __VERIFIER_nondet_float();
float octant = pi / 3;
assume(x > octant && x < pi);
float oddExp = x;
float evenExp = 1.0;
float term = x;
unsigned int count = 2;
int multFactor = 0;
int temp;
while (1) {
term = term * (x / count);
multFactor = (count >> 1 % 2 == 0) ? 1 : -1;
evenExp = evenExp + multFactor * term;
count++;
term = term * (x / count);
oddExp = oddExp + multFactor * term;
count++;
temp = __VERIFIER_nondet_int();
if (temp == 0) {
break;
}
}
assert(oddExp >= evenExp);
return 0;
}