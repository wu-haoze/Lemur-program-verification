void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assume((x >= 1) && (n <= n));
while ((x > 1)) {
assert((x >= 1) && (n <= n));
{
(x = (x - 1));
}
}
if ((n >= 0)) {
}
}