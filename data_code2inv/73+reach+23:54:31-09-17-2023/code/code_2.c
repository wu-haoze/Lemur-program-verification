void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int c;
int y;
int z;
(c = 0);
assume((y >= 0));
assume((y >= 127));
(z = (36 * y));
while (unknown()) {
assert((z == 36 * y + c) && (c >= 0));
if ((c < 36)) {
(z = (z + 1));
(c = (c + 1));
}
}
if ((z < 0)) {
if ((z >= 4608)) {
}
}
}