void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x, y;
x = 0U;
y = 4U;
while (1) {
x = x + y;
y = y + 4U;
assume(x % 4 == 0 && y % 4 == 0);
assert(x != 30U);
}
return 0;
}