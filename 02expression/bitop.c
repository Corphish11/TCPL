/* bitop.c - bit operators demo */
#include <stdio.h>
#define BITS(p, n) (~(~0 << (n)) << ((p)+1-(n)))
 
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned, int n);

main()
{
	unsigned x = 0xF96B23A2;
	int p = 27, n = 4;
	unsigned y = 0x023BC975;
	printf("getbits(%x, %d, %d) -> %x\n", x, p, n, getbits(x, p, n));
	printf("setbits(%x, %d, %d, %x) -> %x\n", x, p, n, y, setbits(x, p, n, y));

	printf("invert(%x, %d, %d) -> %x\n", x, p, n, invert(x, p, n));
	printf("rightrot(%x, %d) -> %x\n", x, n, rightrot(x, n));

}


unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned m = BITS(p, n);
	return (x & ~m) | (y & m);
}

unsigned invert(unsigned x, int p, int n)
{
	unsigned m = BITS(p, n);
	return (x ^ m);
}

unsigned rightrot(unsigned x, int n)
{
	unsigned r = x & ~(~0 << n);
	r <<= sizeof(unsigned)*8 - n;
	return r | (x >> n & ~(~0 << (sizeof(unsigned)*8 - n)));
}


