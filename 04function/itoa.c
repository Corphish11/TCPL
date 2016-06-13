/* itoa - convert a number to string recursively */
#include <stdio.h>

void do_itoa(int n, char s[], int *p)
{
	if (n / 10) {
		do_itoa(n / 10, s, p);
	}

	s[(*p)++] = n % 10 + '0';
}

void itoa(int n, char s[]) {
	int p = 0;

	if (n < 0) {
		s[0] = '-';
		n = -n;
		p = 1;
	}

	do_itoa(n, s, &p);

	s[p] = '\0';
}
main()
{
	char s[20];
	itoa(-2348823, s);
	printf("%s\n", s);
}
