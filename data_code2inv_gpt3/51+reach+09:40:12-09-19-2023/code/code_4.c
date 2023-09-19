void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int c;
(c = 0);
while (unknown()) {
assume((c == 0 || c == 1 || c == 2 || c == 3));
{
if (unknown()) {
if ((c != 4)) {
(c = (c + 1));
}
} else {
if ((c == 4)) {
(c = 1);
}
}
}
}
assert((c == 0 || c == 1 || c == 2 || c == 3));
if ((c != 4)) {
}
}