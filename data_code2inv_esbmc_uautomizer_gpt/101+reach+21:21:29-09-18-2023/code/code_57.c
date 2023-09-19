void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
while ((x < n)) {
assume((x >= 0) && (n > x));
{
(x = (x + 1));
}
}
assume((x >= 0) && (n > x));
if ((x != n)) {
assert((n < 0));
}
}