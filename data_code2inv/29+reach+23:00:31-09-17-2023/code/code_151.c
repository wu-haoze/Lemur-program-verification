void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assume(x >= 0 && x <= n && n == x +1);
while ((x > 0)) {
assume(x >= 0 && x <= n && n == x +1);
{
(x = (x - 1));
}
}
if ((n >= 0)) {
assert((x == 0));
}
}