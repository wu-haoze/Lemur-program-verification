void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int lock;
int x;
int y;
(y = (x + 1));
(lock = 0);
while ((x != y)) {
assume((x == y && lock == 0) || (y == x + 1 && lock == 1));
{
if (unknown()) {
{
(lock = 1);
(x = y);
}
} else {
{
(lock = 0);
(x = y);
(y = (y + 1));
}
}
}
}
assert((x == y && lock == 0) || (y == x + 1 && lock == 1));
}