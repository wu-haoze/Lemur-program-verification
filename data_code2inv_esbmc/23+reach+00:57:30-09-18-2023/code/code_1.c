void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
(i = 1);
(j = 20);
while ((j >= i)) {
{
(i = (i + 2));
(j = (j - 1));
}
}
assert((j == 13));
}