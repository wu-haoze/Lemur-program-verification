void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
unsigned int y = 10000000;
unsigned int z = 5000000;
assert(x >= z && x <= y);
while (x < y) {
if (x >= 5000000) {
z++;
}
x++;
}
return 0;
}