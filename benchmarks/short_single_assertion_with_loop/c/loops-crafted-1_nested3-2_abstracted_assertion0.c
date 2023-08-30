void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x = 0;
unsigned int y = 0;
unsigned int z = 0;
unsigned int w = 0;
while (x < 0x0fffffff) {
y = 0;
while (y < 0x0fffffff) {
z = 0;
if (z < (268435455)) {
long long int z__VERIFIER_LA_tmp0;
z__VERIFIER_LA_tmp0 = z;
long long int __VERIFIER_LA_iterations0;
__VERIFIER_LA_iterations0 = (268435455 - z__VERIFIER_LA_tmp0) / 1L;
unsigned int z__VERIFIER_LA_old_tmp0;
z__VERIFIER_LA_old_tmp0 = z;
z = (__VERIFIER_LA_iterations0 * 1L) + z__VERIFIER_LA_old_tmp0;
}
assert(!(z % 4));
y++;
}
x++;
}
return 0;
}