void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 1;
int y;
while (x <= 10) {
y = 10 - x;
x = x + 1;
}
assert(y < 10);
}