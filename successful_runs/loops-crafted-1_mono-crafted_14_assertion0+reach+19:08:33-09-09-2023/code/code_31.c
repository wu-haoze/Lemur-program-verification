void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 500000, z = 0;
x = 0;
assume((x > 499999 && y == 500000 + x - 499999) || (x <= 499999 && y == 500000));
while (x < 1000000) {
assume((x > 499999 && y == 500000 + x - 499999) || (x <= 499999 && y == 500000));
if (x < 500000) {
x++;
} else {
x++;
y++;
}
}
assert(z == x && y % 2 == 0);
while (y > 0) {
x--;
z++;
y = y - 2;
}
return 0;
}