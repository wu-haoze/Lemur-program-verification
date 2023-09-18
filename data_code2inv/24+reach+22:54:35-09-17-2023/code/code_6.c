void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
(i = 1);
(j = 10);
assume(i%2 != 0 && j>=i);
while ((j >= i)) {
assert(i%2 != 0 && j>=i);
{
(i = (i + 2));
(j = (j - 1));
}
}
}