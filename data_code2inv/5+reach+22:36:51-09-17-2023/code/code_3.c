void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int x = 0;
int size;
int y, z;
assert(x >= 0 && x <= size);
while (x < size) {
x += 1;
if (z <= y) {
y = z;
}
}
if (size > 0) {
}
}