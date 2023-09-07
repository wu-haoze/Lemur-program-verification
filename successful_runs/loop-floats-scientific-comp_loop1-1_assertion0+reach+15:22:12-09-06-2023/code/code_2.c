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
assume(term == pow(x,count) / factorial(count));
while (1) {
assume(term == pow(x,count) / factorial(count));
term = term * (x / count);
exp = exp + term;
count++;
temp = __VERIFIER_nondet_int();
if (temp == 0) {
break;
}
}
assert(result >= exp);
return 0;
}