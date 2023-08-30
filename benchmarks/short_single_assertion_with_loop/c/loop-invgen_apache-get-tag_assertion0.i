void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int __VERIFIER_nondet_int();
int main() {
int tagbuf_len;
int t;
tagbuf_len = __VERIFIER_nondet_int();
if (tagbuf_len >= 1) {
;
} else {
goto END;
}
t = 0;
--tagbuf_len;
while (1) {
if (t == tagbuf_len) {
assert(0 <= t);
goto END;
}
if (__VERIFIER_nondet_int()) {
break;
}
t++;
}
t++;
while (1) {
if (t == tagbuf_len) {
goto END;
}
if (__VERIFIER_nondet_int()) {
if (__VERIFIER_nondet_int()) {
t++;
if (t == tagbuf_len) {
goto END;
}
}
} else if (__VERIFIER_nondet_int()) {
break;
}
t++;
}
END:
return 0;
}