void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int n;
int sn;
(sn = 0);
(i = 1);
while ((i <= n)) {
assume(sn == i - 1 && sn >= 0 && i <= n + 1);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
if ((sn != 0)) {
assert((sn == n));
}
}