void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int len;
int i;
int j;
int bufsize;
bufsize = __VERIFIER_nondet_int();
if (bufsize < 0) {
return 0;
}
len = __VERIFIER_nondet_int();
int limit = bufsize - 4;
for (i = 0; i < len;) {
for (j = 0; i < len && j < limit;) {
if (i + 1 < len) {
if (__VERIFIER_nondet_int()) {
goto ELSE;
}
j++;
i++;
assert(0 <= i);
j++;
i++;
j++;
} else {
ELSE:
j++;
i++;
}
}
}
return 0;
}