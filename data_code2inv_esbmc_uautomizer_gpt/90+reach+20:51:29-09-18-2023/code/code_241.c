void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int lock;
int v1;
int v2;
int v3;
int x;
int y;
(y = (x + 1));
(lock = 0);
while ((x != y)) {
assume((x == y && lock == 0) || (x != y && lock == 1));
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