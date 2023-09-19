void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int i = 0;
int j, c, t;
while (unknown()) {
assume(i >= 0);
if (c > 48) {
if (c < 57) {
j = i + i;
t = c - 48;
i = j + t;
}
}
}
assert(i >= 0);
}