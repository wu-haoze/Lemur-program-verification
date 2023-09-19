void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int n;
int v1;
int v2;
int v3;
int x;
(x = 0);
while ((x < n)) {
assume(x >= 0 && x <= n && x == v1 + v2);
{
(x = (x + 1));
}
}
assume(x >= 0 && x <= n && x == v1 + v2);
if ((n >= 0)) {
assert((x == n));
}
}