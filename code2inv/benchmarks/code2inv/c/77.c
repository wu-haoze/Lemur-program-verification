void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int x;
int y;
(i = 0);
assume((x >= 0));
assume((y >= 0));
assume((x >= y));
while (unknown()) {
if ((i < y)) {
(i = (i + 1));
}
}
if ((i < y)) {
assert((i < x));
}
}