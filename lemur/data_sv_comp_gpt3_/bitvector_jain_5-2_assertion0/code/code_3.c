void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x, y;
x = 0U;
y = 4U;
assert((x % 4U) == 0 && (y % 4U) == 0);
while (1) {
x = x + y;
y = y + 4U;
}
return 0;
}