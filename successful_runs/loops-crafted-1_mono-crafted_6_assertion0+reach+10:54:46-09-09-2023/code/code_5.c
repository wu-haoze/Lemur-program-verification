void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0, y = 500000, z = 0;
x = 0;
assume(x <= 750000 && (x >= 500000 || x % 2 ==0) && y > z);
while (x < 1000000) {
assert(x <= 750000 && (x >= 500000 || x % 2 ==0) && y > z);
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
return 0;
}