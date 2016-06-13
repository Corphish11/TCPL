/* getfloat.c - parse float array */
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int c);

int getfloat(double *pn)
{
	int c, sign;
	int power;

	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();
	if (!isdigit(c)) {
		ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c != '.') {
		goto getfloat_ret;
	}
	c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
		power *= 10.0;
	}
	*pn /= power;


getfloat_ret:
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

main()
{
	int r;
	double n;

	while ((r = getfloat(&n)) != EOF && r > 0)
		printf("%f\t", n);
}
