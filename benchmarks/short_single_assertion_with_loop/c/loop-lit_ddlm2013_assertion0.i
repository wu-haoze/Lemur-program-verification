void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
unsigned int i, j, a, b;
int flag = __VERIFIER_nondet_int();
a = 0;
b = 0;
j = 1;
if (flag) {
i = 0;
} else {
i = 1;
}
while (__VERIFIER_nondet_int()) {
a++;
b += (j - i);
i += 2;
if (i % 2 == 0) {
j += 2;
} else {
j++;
}
}
if (flag) {
assert(a == b);
}
return 0;
}