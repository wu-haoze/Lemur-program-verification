void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
while ((x < y)) {
assume((x < y) || (y <= 1));
{
(x = (x + x));
}
}
assume((x < y) || (y <= 1));
assert((x >= 1));
}