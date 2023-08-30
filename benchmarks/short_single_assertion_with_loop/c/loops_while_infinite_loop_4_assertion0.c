void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int x = 0;
void eval(void) {
while (1) {
x = 1;
break;
}
return;
}
int main() {
while (1) {
eval();
assert(x == 0);
}
return 0;
}