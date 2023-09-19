void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
(x = 10000);
while ((x > 0)) {
assume((x > 0) || (x == 10000));
{
(x = (x - 1));
}
}
assume((x > 0) || (x == 10000));
assert((x == 0));
}