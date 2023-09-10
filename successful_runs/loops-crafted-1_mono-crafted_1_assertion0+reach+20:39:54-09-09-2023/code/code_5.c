void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 50000, z = 0;
x = 0;
assume(x <= 50000 && y == 50000 + x);
while (x < 1000000) {
assert(x <= 50000 && y == 50000 + x);
if (x < 50000) {
x++;
} else {
x++;
y++;
}
}
while (y > z) {
y--;
x--;
}
return 0;
}