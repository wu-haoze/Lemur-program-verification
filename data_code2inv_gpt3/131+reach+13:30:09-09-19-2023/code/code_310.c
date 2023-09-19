void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int d1 = 1;
int d2 = 1;
int d3 = 1;
int x1 = 1;
int x2, x3;
while (x1 > 0) {
assert(x1 >= 0 && x2 >= 0 && (x3 >= d3 || x1 <= 0));
if (x2 > 0) {
if (x3 > 0) {
x1 = x1 - d1;
x2 = x2 - d2;
x3 = x3 - d3;
}
}
}
}