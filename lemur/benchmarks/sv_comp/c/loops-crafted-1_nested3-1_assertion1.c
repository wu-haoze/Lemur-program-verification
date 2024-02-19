void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x = 0;
unsigned int y = 0;
unsigned int z = 0;
unsigned int w = 0;
while (x < 0x0fffffff) {
y = 0;
while (y < 0x0fffffff) {
z = 0;
while (z < 0x0fffffff) {
z++;
}
y++;
}
assert(y % 2);
x++;
}
return 0;
}
