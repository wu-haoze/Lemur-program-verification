void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int size;
int sn;
(sn = 0);
(i = 1);
while ((i <= size)) {
assume(sn + i - 1 == size);
{
(i = (i + 1));
(sn = (sn + 1));
}
}
assert(sn + i - 1 == size);
if ((sn != size)) {
}
}