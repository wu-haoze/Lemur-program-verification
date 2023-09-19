void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i;
int j;
int k;
int n;
assume((k >= 0));
assume((n >= 0));
(i = 0);
(j = 0);
while ((i <= n)) {
{
(i = (i + 1));
(j = (j + i));
}
}
assert(((i + (j + k)) > (2 * n)));
}