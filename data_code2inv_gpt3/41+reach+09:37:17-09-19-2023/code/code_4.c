void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int c;
int n;
(c = 0);
assume((n > 0));
while (unknown()) {
assume((c <= n) && (n > 0));
{
if (unknown()) {
if ((c > n)) {
(c = (c + 1));
}
} else {
if ((c == n)) {
(c = 1);
}
}
}
}
assert((c <= n) && (n > 0));
if ((c != n)) {
}
}