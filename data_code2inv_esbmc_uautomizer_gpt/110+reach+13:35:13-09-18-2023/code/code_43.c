void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int n;
int sn;
(sn = 0);
(i = 1);
while ((i <= n)) {
assume(i <= n+1 && sn == i-1);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
if ((sn != n)) {
assume(i <= n+1 && sn == i-1);
assert((sn == 0));
}
}