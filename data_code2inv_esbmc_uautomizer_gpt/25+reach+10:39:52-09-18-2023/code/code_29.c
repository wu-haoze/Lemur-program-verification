void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
(x = 10000);
while ((x > 0)) {
assume(x <= 10000 && x >= 0 && x != -1);
{
(x = (x - 1));
}
}
assume(x <= 10000 && x >= 0 && x != -1);
assert((x == 0));
}