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
assume((2*x + y == 3*i) && (x + 2*y >= 3*i));
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
assert(((3 * n) == (x + y)));
}