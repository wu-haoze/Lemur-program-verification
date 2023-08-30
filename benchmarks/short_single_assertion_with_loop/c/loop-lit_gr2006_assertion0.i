void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int x, y;
x = 0;
y = 0;
while (1) {
if (x < 50) {
y++;
} else {
y--;
}
if (y < 0) {
break;
}
x++;
}
assert(x == 100);
return 0;
}