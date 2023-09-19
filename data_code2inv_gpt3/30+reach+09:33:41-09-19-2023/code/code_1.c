void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
(x = 100);
while ((x > 0)) {
{
(x = (x - 1));
}
}
assert((x == 0));
}