void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int size;
int sn;
(sn = 0);
(i = 1);
while ((i <= size)) {
assume(i <= sn + 1 && i >= 1 && sn < size);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
assume(i <= sn + 1 && i >= 1 && sn < size);
if ((sn != 0)) {
assert((sn == size));
}
}