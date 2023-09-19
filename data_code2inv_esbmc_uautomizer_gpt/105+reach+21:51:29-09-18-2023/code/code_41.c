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
assume(x <= n && x >= 0 && (x == 0 || v1 != v2) && (v3 > n || x < v3));
{
(x = (x + 1));
}
}
assume(x <= n && x >= 0 && (x == 0 || v1 != v2) && (v3 > n || x < v3));
if ((n >= 0)) {
assert((x == n));
}
}