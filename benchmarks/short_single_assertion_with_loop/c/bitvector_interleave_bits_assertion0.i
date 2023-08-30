void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int main() {
unsigned short x = __VERIFIER_nondet_ushort();
unsigned short y = __VERIFIER_nondet_ushort();
unsigned int xx;
unsigned int yy;
unsigned int zz;
unsigned int z = 0;
unsigned int i = 0;
while (i < sizeof(x) * 8) {
z |= ((x & (1U << i)) << i) | ((y & (1U << i)) << (i + 1));
i += 1U;
}
xx = x;
yy = y;
xx = (xx | (xx << 8u)) & 16711935U;
xx = (xx | (xx << 4u)) & 252645135U;
xx = (xx | (xx << 2u)) & 858993459U;
xx = (xx | (xx << 1u)) & 1431655765U;
yy = (yy | (yy << 8u)) & 16711935U;
yy = (yy | (yy << 4u)) & 252645135U;
yy = (yy | (yy << 2u)) & 858993459U;
yy = (yy | (yy << 1u)) & 1431655765U;
zz = xx | (yy << 1U);
assert(z == zz);
}