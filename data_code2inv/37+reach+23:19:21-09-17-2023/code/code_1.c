void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int c;
(c = 0);
while (unknown()) {
assume((c >= 0) && (c <= 40));
{
if (unknown()) {
if ((c != 40)) {
(c = (c + 1));
}
} else {
if ((c == 40)) {
(c = 1);
}
}
}
}
if ((c < 0)) {
if ((c > 40)) {
assert((c == 40));
}
}
}