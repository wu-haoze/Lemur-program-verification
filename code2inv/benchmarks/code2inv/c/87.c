void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int lock;
int x;
int y;
(x = y);
(lock = 1);
while ((x != y)) {
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
assert((lock == 1));
}