void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
double x = 1.0;
double x1 = x / 2.5;
while (x1 != x) {
x = x1;
x1 = x / 2.5;
}
assert(x == 0);
return 0;
}