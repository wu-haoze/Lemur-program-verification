void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
(y = 0);
assume(x == (y*(y+1))/2 && y <= 1000);
while ((y < 1000)) {
assume(x == (y*(y+1))/2 && y <= 1000);
{
(x = (x + y));
(y = (y + 1));
}
}
assert((x >= y));
}