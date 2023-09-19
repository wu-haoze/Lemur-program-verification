void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
assume((x >= 0));
assume((x <= 10));
assume((y <= 10));
assume((y >= 0));
while (unknown()) {
assert((x >= 0 && x <= 10) || (y == 0));
{
(x = (x + 10));
(y = (y + 10));
}
}
if ((y == 0)) {
}
}