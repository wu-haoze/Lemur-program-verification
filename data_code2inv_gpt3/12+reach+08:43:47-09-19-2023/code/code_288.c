void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
int z1;
int z2;
int z3;
assume((x >= 0));
assume((x <= 10));
assume((y <= 10));
assume((y >= 0));
while (unknown()) {
assume((x <= 10) && (y <= 10));
{
(x = (x + 10));
(y = (y + 10));
}
}
assume((x <= 10) && (y <= 10));
if ((y == 0)) {
assert((x != 20));
}
}