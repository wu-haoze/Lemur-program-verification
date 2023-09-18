void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assume(x <= n && x >= 2);
while ((x > 1)) {
assume(x <= n && x >= 2);
{
(x = (x - 1));
}
}
if ((x != 1)) {
assert((n < 0));
}
}