/* atof.c - convert string to float */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE	1000


main()
{
	double sum;
	char line[MAXLINE];
	int my_getline(char line[], int lim);
	double atof(char s[]);

	sum = 0;
	while (my_getline(line, MAXLINE) != 0)
		printf("\t%f\n", sum += atof(line));	
	return 0;
}


double
atof(char s[])
{
	double val, power;
	int i, sign;
	int esign, enu;

	for (i = 0; isspace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (val == 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	if (s[i] == 'E' || s[i] == 'e')
		++i;
	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;
	for (enu = 0; isdigit(s[i]); ++i)
		enu = enu * 10 + (s[i] - '0');
	while (enu-- > 0)
		power *= (esign == -1) ? 10 : 0.1;

	return sign * val / power;
}
