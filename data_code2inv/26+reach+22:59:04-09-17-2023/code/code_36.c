void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = n);
assert(x <= n && x > 0);
while ((x > 1)) {
{
(x = (x - 1));
}
}
if ((x != 1)) {
}
}