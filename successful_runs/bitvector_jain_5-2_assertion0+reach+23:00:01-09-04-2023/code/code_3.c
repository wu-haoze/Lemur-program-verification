void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x, y;
x = 0U;
y = 4U;
assume(x % 4 == 0);
while (1) {
assert(x % 4 == 0);
x = x + y;
y = y + 4U;
}
return 0;
}