void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
assume((n >= 0));
while ((x < n)) {
assume((x <= n) && (n >= 0) && (x >= 0));
{
(x = (x + 1));
}
}
assume((x <= n) && (n >= 0) && (x >= 0));
assert((x == n));
}