void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
while ((x < y)) {
assume(y == 0 || (x > 0));
{
(x = (x + x));
}
}
assume(y == 0 || (x > 0));
assert((x >= 1));
}