void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
(y = 0);
assert(x == ((y * (y - 1)) / 2) + 1);
while ((y < 100000)) {
{
(x = (x + y));
(y = (y + 1));
}
}
}