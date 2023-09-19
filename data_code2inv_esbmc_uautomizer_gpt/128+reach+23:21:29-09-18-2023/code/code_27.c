void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
while ((x < y)) {
assume(y != 0 && (x == pow(2, ceil(log2(x)))));
{
(x = (x + x));
}
}
assume(y != 0 && (x == pow(2, ceil(log2(x)))));
assert((x >= 1));
}