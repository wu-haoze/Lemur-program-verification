void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
int x;
int y;
(j = 0);
(i = 0);
(y = 2);
while ((i <= x)) {
assert(i == j/y);
{
(i = (i + 1));
(j = (j + y));
}
}
if ((y == 1)) {
}
}