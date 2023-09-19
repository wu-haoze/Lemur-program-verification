void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int size;
int sn;
(sn = 0);
(i = 1);
while ((i <= size)) {
assume(i <= size && sn + i - 1 == i);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
assert(i <= size && sn + i - 1 == i);
if ((sn != 0)) {
}
}