void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int sn;
(sn = 0);
(i = 1);
while ((i <= 8)) {
assume(i == sn + 1);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
if ((sn != 8)) {
assert((sn == 0));
}
}