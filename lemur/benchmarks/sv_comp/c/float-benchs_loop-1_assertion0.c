void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
float x, y, z;
x = 1.f;
y = 1e7;
z = 42.f;
while (x < y) {
x = x + 1.f;
y = y - 1.f;
z = z + 1.f;
}
assert(z >= 0.f && z <= 1e8);
return 0;
}
