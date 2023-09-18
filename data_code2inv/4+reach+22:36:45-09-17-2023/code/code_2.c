void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int y, z;
assume(x >= 0 && x <= 500);
while (x < 500) {
assert(x >= 0 && x <= 500);
x += 1;
if (z <= y) {
y = z;
}
}
}