void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
(x = 10000);
assert(x <= 10000 && x >= 0);
while ((x > 0)) {
{
(x = (x - 1));
}
}
}