void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 50000, z = 0;
x = 0;
assume(x >= 0 && x <= 1000000);
while (x < 1000000) {
assume(x >= 0 && x <= 1000000);
if (x < 50000) {
x++;
} else {
x = x + 2;
y = y + 2;
}
}
assert(y >= z && x == y);
while (y > z) {
y--;
x--;
}
return 0;
}