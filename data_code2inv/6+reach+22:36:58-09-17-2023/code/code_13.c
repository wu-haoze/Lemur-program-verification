void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int v1, v2, v3;
int x = 0;
int size;
int y, z;
assume(y <= z || y == v2 || y == v3);
while (x < size) {
assume(y <= z || y == v2 || y == v3);
x += 1;
if (z <= y) {
y = z;
}
}
if (size > 0) {
assert(z >= y);
}
}