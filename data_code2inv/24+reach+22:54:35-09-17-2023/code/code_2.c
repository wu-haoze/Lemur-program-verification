void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
(i = 1);
(j = 10);
assume(i + j == 11);
while ((j >= i)) {
assert(i + j == 11);
{
(i = (i + 2));
(j = (j - 1));
}
}
}