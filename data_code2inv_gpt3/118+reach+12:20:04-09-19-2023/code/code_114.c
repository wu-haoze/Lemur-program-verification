void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int size;
int sn;
(sn = 0);
(i = 1);
while ((i <= size)) {
assume((sn + (size - i) == 0 && sn >= 0));
{
(i = (i + 1));
(sn = (sn + 1));
}
}
assume((sn + (size - i) == 0 && sn >= 0));
if ((sn != size)) {
assert((sn == 0));
}
}