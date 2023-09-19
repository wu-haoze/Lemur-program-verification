void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int sn;
int x;
(sn = 0);
(x = 0);
while (unknown()) {
assume(sn == x);
{
(x = (x + 1));
(sn = (sn + 1));
}
}
assume(sn == x);
if ((sn != -1)) {
assert((sn == x));
}
}