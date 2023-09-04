void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
long double x = 1.0 / 7.0;
long long res = 0;
for (int i = 1; x != 0; i++) {
res += ((int)(x * 10) % 10) * (i * 10);
x = (x * 10) - (int)x * 10;
}
assert(res == 67050);
return 0;
}