void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
assume((x >= 0));
assume((x <= 10));
assume((y <= 10));
assume((y >= 0));
assume(x == y);
while (unknown()) {
assert(x == y);
{
(x = (x + 10));
(y = (y + 10));
}
}
if ((x == 20)) {
}
}