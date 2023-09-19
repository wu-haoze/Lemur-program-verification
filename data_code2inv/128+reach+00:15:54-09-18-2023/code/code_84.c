void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
while ((x < y)) {
assert(x >= 1 && x < y && (y % x == 0 || y / x < 2));
{
(x = (x + x));
}
}
}