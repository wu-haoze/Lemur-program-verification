void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
unsigned int y = 10000000;
unsigned int z = 5000000;
assume(x <= y && z == 5000000 + x / 2);
while (x < y) {
assume(x <= y && z == 5000000 + x / 2);
if (x >= 5000000) {
z++;
}
x++;
}
assert(z == x);
return 0;
}