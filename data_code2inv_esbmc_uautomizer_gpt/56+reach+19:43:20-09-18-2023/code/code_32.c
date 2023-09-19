void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int c;
int n;
int v1;
int v2;
int v3;
(c = 0);
assume((n > 0));
while (unknown()) {
assume((c >= 0 && c <= n+1) && (c != n || v2 == v3));
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
if ((c == n)) {
assert((n <= -1));
}
}