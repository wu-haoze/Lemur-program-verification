void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
float x = 1.0f;
float x1 = x / 1.6f;
while (x1 != x) {
x = x1;
x1 = x / 1.6f;
}
assert(x == 0);
return 0;
}