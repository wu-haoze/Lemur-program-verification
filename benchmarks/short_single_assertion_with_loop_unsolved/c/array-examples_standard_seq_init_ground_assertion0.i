void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
int a[100000];
int i;
i = 1;
a[0] = 7;
while (i < 100000) {
a[i] = a[i - 1] + 1;
i = i + 1;
}
int x;
for (x = 1; x < 100000; x++) {
assert(a[x] >= a[x - 1]);
}
return 0;
}