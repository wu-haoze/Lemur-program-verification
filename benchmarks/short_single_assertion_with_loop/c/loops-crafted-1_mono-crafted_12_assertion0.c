void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x = 0;
unsigned int y = 10000000;
unsigned int z = 0;
while (x < y) {
if (x >= 5000000) {
z = z + 2;
}
x++;
}
assert(!(z % 2));
return 0;
}