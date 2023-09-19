void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int size;
int sn;
int v1;
int v2;
int v3;
(sn = 0);
(i = 1);
while ((i <= size)) {
assume((i <= size) && (sn == i));
{
(i = (i + 1));
(sn = (sn + 1));
}
}
if ((sn != size)) {
assert((sn == 0));
}
}