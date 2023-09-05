void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned char n = __VERIFIER_nondet_uchar();
if (n == 0) {
return 0;
}
unsigned char v = 0;
unsigned int s = 0;
unsigned int i = 0;
assume(s >= 0 && s <= i*0xff);
while (i < n) {
assert(s >= 0 && s <= i*0xff);
v = __VERIFIER_nondet_uchar();
s += v;
++i;
}
return 0;
}