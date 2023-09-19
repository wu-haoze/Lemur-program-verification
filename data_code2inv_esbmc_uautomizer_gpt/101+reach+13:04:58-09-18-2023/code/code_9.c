void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int x;
(x = 0);
while ((x < n)) {
assume(x >= 0 && x <= n && (x != n || n < 0));
{
(x = (x + 1));
}
}
if ((x != n)) {
assume(x >= 0 && x <= n && (x != n || n < 0));
assert((n < 0));
}
}