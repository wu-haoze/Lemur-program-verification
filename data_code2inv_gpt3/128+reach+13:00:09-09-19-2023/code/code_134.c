void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
while ((x < y)) {
assume((y > x || y <= x));
{
(x = (x + x));
}
}
assume((y > x || y <= x));
assert((x >= 1));
}