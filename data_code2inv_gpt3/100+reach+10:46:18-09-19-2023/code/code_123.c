void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
int y;
assume((n >= 0));
(x = n);
(y = 0);
while ((x > 0)) {
assume((y >= 0) && (x > 0));
{
(y = (y + 1));
(x = (x - 1));
}
}
assert((y == n));
}