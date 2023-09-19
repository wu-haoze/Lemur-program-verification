void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x;
int y;
(x = 1);
while ((x < y)) {
assume((x >= 1) && (pow(2, floor(log(x)/log(2))) == x));
{
(x = (x + x));
}
}
assume((x >= 1) && (pow(2, floor(log(x)/log(2))) == x));
assert((x >= 1));
}