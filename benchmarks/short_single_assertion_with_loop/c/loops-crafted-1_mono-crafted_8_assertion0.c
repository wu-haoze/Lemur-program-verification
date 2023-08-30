void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x = 0;
unsigned int y = 10000000;
unsigned int z = 5000000;
while (x < y) {
if (x >= 5000000) {
z--;
}
x++;
}
assert(z == 0);
return 0;
}