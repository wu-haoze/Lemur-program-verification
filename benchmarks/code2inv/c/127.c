void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
int x;
int y;
int z1;
int z2;
int z3;
(i = x);
(j = y);
while ((x != 0)) {
{
(x = (x - 1));
(y = (y - 1));
}
}
if ((y != 0)) {
assert((i != j));
}
}