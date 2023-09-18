void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int v1, v2, v3;
int x = 0;
int size;
int y, z;
assert(x >= 0 && x <= size && y <= z);
while (x < size) {
x += 1;
if (z <= y) {
y = z;
}
}
if (size > 0) {
}
}