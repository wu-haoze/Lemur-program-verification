void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assume((x <= n) && (x > 0));
while ((x > 1)) {
assert((x <= n) && (x > 0));
{
(x = (x - 1));
}
}
if ((n >= 0)) {
}
}