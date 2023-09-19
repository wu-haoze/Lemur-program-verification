void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
assume((n >= 0));
while ((x < n)) {
assume(x >= 0 && x <= n && n == (x + count(n - x)));
{
(x = (x + 1));
}
}
assert((x == n));
}