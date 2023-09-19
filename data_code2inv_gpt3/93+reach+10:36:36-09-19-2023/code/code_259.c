void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int n;
int x;
int y;
assume((n >= 0));
(i = 0);
(x = 0);
(y = 0);
while ((i < n)) {
assume((i <= n) && (x == i + 2 * y));
{
(i = (i + 1));
if (unknown()) {
{
(x = (x + 1));
(y = (y + 2));
}
} else {
{
(x = (x + 2));
(y = (y + 1));
}
}
}
}
assume((i <= n) && (x == i + 2 * y));
assert(((3 * n) == (x + y)));
}