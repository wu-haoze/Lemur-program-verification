void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int x;
int y;
int z1;
int z2;
int z3;
(i = 0);
assume((x >= 0));
assume((y >= 0));
assume((x >= y));
while (unknown()) {
if ((i < y)) {
(i = (i + 1));
}
}
if ((i >= x)) {
if ((0 > i)) {
assert((i >= y));
}
}
}