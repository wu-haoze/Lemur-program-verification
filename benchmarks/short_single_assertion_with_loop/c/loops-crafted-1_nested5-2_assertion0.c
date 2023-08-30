void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned int x = 0;
unsigned int y = 0;
unsigned int z = 0;
unsigned int w = 0;
unsigned int v = 0;
for (w = 0; w < 0x0fffffff; w++) {
for (x = 0; x < 10; x++) {
for (y = 0; y < 10; y++) {
for (z = 0; z < 10; z++) {
for (v = 0; v < 0x0fffffff; v++) {
;
}
assert(!(v % 4));
}
}
}
}
return 0;
}