void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int n;
int sn;
int v1;
int v2;
int v3;
(sn = 0);
(i = 1);
while ((i <= n)) {
assume(i <= n && sn == i + 1);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
assume(i <= n && sn == i + 1);
if ((sn != 0)) {
assert((sn == n));
}
}