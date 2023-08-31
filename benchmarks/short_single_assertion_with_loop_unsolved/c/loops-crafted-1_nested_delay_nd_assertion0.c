void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int last;
int SIZE = 200000;
int main() {
last = __VERIFIER_nondet_int();
assume(last > 0);
int a = 0, b = 0, c = 0, st = 0, d = 0;
while (1) {
st = 1;
for (c = 0; c < SIZE; c++) {
if (c >= last) {
st = 0;
}
}
if (st == 0 && c == last + 1) {
a += 3;
b += 3;
} else {
a += 2;
b += 2;
}
if (c == last && st == 0) {
a = a + 1;
} else if (st == 1 && last < SIZE) {
d++;
}
if (d == SIZE) {
a = 0;
b = 1;
}
assert(a == b && c == SIZE);
}
return 0;
}