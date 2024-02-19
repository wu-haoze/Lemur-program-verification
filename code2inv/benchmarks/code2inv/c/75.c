void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int c;
int x1;
int x2;
int x3;
int y;
int z;
(c = 0);
assume((y >= 0));
assume((y >= 127));
(z = (36 * y));
while (unknown()) {
if ((c < 36)) {
(z = (z + 1));
(c = (c + 1));
}
}
if ((c < 36)) {
assert((z < 4608));
}
}