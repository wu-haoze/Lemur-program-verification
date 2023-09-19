void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int size;
int sn;
(sn = 0);
(i = 1);
while ((i <= size)) {
assume(i >= 1 && sn == i-1 && size >= sn);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
if ((sn != 0)) {
assert((sn == size));
}
}