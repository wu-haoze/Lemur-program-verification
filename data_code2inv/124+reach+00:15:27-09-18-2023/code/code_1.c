void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
int x;
int y;
(i = x);
(j = y);
while ((x != 0)) {
assume((i-x) == (j-y));
{
(x = (x - 1));
(y = (y - 1));
}
}
if ((i == j)) {
assert((y == 0));
}
}