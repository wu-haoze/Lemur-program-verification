void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
assume((n >= 0));
while ((x < n)) {
assume(n == (x + count));
{
(x = (x + 1));
}
}
assume(n == (x + count));
assert((x == n));
}