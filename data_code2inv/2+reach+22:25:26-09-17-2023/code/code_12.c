void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
(y = 0);
assume(y <= 1000 && y >= x - y);
while ((y < 1000)) {
assert(y <= 1000 && y >= x - y);
{
(x = (x + y));
(y = (y + 1));
}
}
}