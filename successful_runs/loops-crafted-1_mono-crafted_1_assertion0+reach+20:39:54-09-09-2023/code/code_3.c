void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 50000, z = 0;
x = 0;
while (x < 1000000) {
if (x < 50000) {
x++;
} else {
x++;
y++;
}
}
assert(y >= z && x == y);
while (y > z) {
y--;
x--;
}
return 0;
}