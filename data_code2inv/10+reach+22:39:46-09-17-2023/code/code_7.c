void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
assume((x >= 0));
assume((x <= 2));
assume((y <= 2));
assume((y >= 0));
assume((x == y) || (x - 2 == y));
while (unknown()) {
assume((x == y) || (x - 2 == y));
{
(x = (x + 2));
(y = (y + 2));
}
}
if ((y == 0)) {
assert((x != 4));
}
}