void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int y = 500000;
assume(x == y - 500000);
while (x < 1000000) {
assert(x == y - 500000);
if (x < 500000) {
x = x + 1;
} else {
x = x + 1;
y = y + 1;
}
}
return 0;
}