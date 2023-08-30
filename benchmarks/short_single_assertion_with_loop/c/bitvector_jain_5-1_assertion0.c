void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x, y;
x = 0;
y = 4;
while (1) {
x = x + y;
y = y + 4;
assert(x != 30);
}
return 0;
}