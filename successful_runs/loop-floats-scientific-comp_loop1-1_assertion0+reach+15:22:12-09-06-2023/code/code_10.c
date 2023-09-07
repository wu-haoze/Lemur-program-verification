void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
float x = __VERIFIER_nondet_float();
assume(x > -1.0);
assume(x < 1.0);
float exp = 1.0;
float term = 1.0;
unsigned int count = 1;
float result = 2 * (1 / (1 - x));
int temp;
assume(exp <= result);
while (1) {
assert(exp <= result);
term = term * (x / count);
exp = exp + term;
count++;
temp = __VERIFIER_nondet_int();
if (temp == 0) {
break;
}
}
return 0;
}