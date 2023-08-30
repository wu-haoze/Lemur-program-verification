void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int SIZE = 50000001;
int __VERIFIER_nondet_int();
int main() {
int i, j;
i = 0;
j = 0;
while (i < SIZE) {
if (__VERIFIER_nondet_int()) {
i = i + 8;
} else {
i = i + 4;
}
}
j = i / 4;
assert((j * 4) == i);
return 0;
}