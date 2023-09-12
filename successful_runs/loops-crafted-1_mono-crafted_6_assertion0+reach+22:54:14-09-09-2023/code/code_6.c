void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 500000, z = 0;
x = 0;
assume(x < 500000 || (x >= 500000 && x < 750000) || x >= 750000);
while (x < 1000000) {
assume(x < 500000 || (x >= 500000 && x < 750000) || x >= 750000);
if (x < 500000) {
x++;
} else {
if (x < 750000) {
x++;
} else {
x = x + 2;
}
y++;
}
}
assert(x == 1000000);
return 0;
}