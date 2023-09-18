void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int y, z;
assert(x >= 0 && x <= 5);
while (x < 5) {
x += 1;
if (z <= y) {
y = z;
}
}
}