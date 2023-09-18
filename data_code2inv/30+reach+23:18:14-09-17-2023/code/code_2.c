void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
(x = 100);
while ((x > 0)) {
assert(x >= 0 && x <= 100);
{
(x = (x - 1));
}
}
}