void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 0;
assume((x <= 10000000) || (x % 2 == 0));
while (x < 100000000) {
assume((x <= 10000000) || (x % 2 == 0));
if (x < 10000000) {
x++;
} else {
x += 2;
}
}
assert(x == 100000000);
}