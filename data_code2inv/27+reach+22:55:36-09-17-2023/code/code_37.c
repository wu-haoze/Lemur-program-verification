void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assume((x >= 1) && (x <= n));
while ((x > 1)) {
assume((x >= 1) && (x <= n));
{
(x = (x - 1));
}
}
if ((n >= 0)) {
assert((x == 1));
}
}