void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int y = 0;
while (y >= 0) {
assert(y == 0 && x == 0);
y = y + x;
}
}