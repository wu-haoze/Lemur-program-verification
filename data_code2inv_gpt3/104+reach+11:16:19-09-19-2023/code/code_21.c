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
assume((x + 1) >= 0 && (x + 1) <= n);
{
(x = (x + 1));
}
}
assume((x + 1) >= 0 && (x + 1) <= n);
if ((x != n)) {
assert((n < 0));
}
}