void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 50000, z = 0;
x = 0;
while (x < 1000000) {
if (x < 50000) {
x++;
} else {
x = x + 2;
y = y + 2;
}
}
assume(y >= z && x == y);
while (y > z) {
assert(y >= z && x == y);
y--;
x--;
}
return 0;
}