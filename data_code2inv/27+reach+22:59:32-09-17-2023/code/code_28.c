void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assume((x <= n) && (x >= 1) && (n >= x));
while ((x > 1)) {
assume((x <= n) && (x >= 1) && (n >= x));
{
(x = (x - 1));
}
}
if ((n >= 0)) {
assert((x == 1));
}
}