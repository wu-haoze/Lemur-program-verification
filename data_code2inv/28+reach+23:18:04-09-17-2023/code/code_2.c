void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
while ((x > 0)) {
assert((x >= 0) && (x <= n));
{
(x = (x - 1));
}
}
if ((x != 0)) {
}
}