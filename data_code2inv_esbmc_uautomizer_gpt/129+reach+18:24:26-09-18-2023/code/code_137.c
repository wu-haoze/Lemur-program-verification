void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
int z1;
int z2;
int z3;
(x = 1);
while ((x < y)) {
assume(x >= 1 && x < y && x != 0);
{
(x = (x + x));
}
}
assume(x >= 1 && x < y && x != 0);
assert((x >= 1));
}