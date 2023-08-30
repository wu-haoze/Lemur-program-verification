void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main(void) {
unsigned int x = 1;
unsigned int y = 0;
while (y < 1024) {
x = 0;
y++;
}
assert(x == 1);
}