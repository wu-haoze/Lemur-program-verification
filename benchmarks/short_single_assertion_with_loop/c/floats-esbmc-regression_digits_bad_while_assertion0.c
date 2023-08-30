void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
long double x = 1.0 / 7.0;
long long res = 0;
int i = 1;
while (x != 0) {
res += ((int)(x * 10) % 10) * (i * 10);
x = (x * 10) - (int)x * 10;
i++;
}
assert(res > 67050);
return 0;
}