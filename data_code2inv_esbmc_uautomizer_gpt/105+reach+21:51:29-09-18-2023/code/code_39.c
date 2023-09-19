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
assume(x <= n && x >= 0 && (n < 0 || x == n));
{
(x = (x + 1));
}
}
assert(x <= n && x >= 0 && (n < 0 || x == n));
if ((n >= 0)) {
}
}