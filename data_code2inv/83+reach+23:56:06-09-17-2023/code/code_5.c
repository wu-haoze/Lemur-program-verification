void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = -5000);
while ((x < 0)) {
assume((x <= 0 && y == -5000 + x));
{
(x = (x + y));
(y = (y + 1));
}
}
assert((y > 0));
}