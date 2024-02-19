void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int sn;
int v1;
int v2;
int v3;
int x;
(sn = 0);
(x = 0);
while (unknown()) {
{
(x = (x + 1));
(sn = (sn + 1));
}
}
if ((sn != -1)) {
assert((sn == x));
}
}