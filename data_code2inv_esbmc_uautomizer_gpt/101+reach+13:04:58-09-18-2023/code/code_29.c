void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
while ((x < n)) {
assume(x >= 0 && x < n && n >= 1);
{
(x = (x + 1));
}
}
if ((x != n)) {
assume(x >= 0 && x < n && n >= 1);
assert((n < 0));
}
}