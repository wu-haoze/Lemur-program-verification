void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
char __VERIFIER_nondet_char();
int main(void) {
char input_string[5], vogal_array[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', '\0'};
;
unsigned int i, j, cont, tam_string, n_caracter;
for (i = 0; i < 5; i++) {
input_string[i] = __VERIFIER_nondet_char();
}
if (!(input_string[5 - 1] == '\0')) {
return 0;
}
n_caracter = 0;
while (input_string[n_caracter] != '\0') {
n_caracter++;
}
cont = 0;
for (i = 0; i < n_caracter; i++) {
for (j = 0; j < 5 / 2; j++) {
if (input_string[i] == vogal_array[j]) {
cont++;
}
}
}
i = 0;
int cont_aux = 0;
while (input_string[i] != '\0') {
for (j = 0; j < 5 / 2; j++) {
if (input_string[i] == vogal_array[j]) {
cont_aux++;
}
}
i++;
}
assert(cont_aux == cont);
return 0;
}