void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
while ((x < n)) {
assume((x <= n) && ((n >= 0 && x == (n+1)) || (n < 0)));
{
(x = (x + 1));
}
}
assert((x <= n) && ((n >= 0 && x == (n+1)) || (n < 0)));
if ((x != n)) {
}
}