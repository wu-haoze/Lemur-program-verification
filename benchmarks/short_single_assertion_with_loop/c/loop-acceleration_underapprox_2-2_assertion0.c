void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
unsigned int y = 1;
while (x < 6) {
x++;
y *= 2;
}
assert(x == 6);
}