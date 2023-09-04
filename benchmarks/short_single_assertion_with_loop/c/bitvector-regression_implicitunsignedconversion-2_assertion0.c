void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int plus_one = 1;
int minus_one = -1;
assert(plus_one <= minus_one);
return (0);
}