void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 1;
int y;
while (x <= 100) {
y = 100 - x;
x = x + 1;
}
assert(y >= 0);
}