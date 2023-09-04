void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 10;
while (x >= 10) {
x += 2;
}
assert(x % 2);
}