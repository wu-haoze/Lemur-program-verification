void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
(x = 0);
while ((x < 100)) {
{
(x = (x + 1));
}
}
assert((x == 100));
}