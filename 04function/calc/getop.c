/* getop.c - get next operator */
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	static int pushback = -1;
	int i, c;

	while ((s[0] = c = (pushback == -1 ? getchar() : pushback)) == ' ' || c == '\t')
		pushback = -1;

	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-' && c != '\'')
		return c;		/* not a number */

	i = 0;

	if (c == '\'') {		/* function operator */
		while (isalnum((s[++i] = c = getchar())))
			;
		if (c != EOF)
			pushback = c;
		s[i] = '\0';
		return FUNC;
	} else {

		if (c == '-') {
			s[1] = c = getchar();
			i = 1;
		}

		if (isdigit(c))			/* collect integer part */
			while (isdigit(s[++i] = c = getchar()))
			;
		if (c == '.')			/* colloct fractional part */
			while (isdigit(s[++i] = c = getchar()))
			;

		s[i] = '\0';

		/* '-' is not unary operator if the following character is not digit */
		if (strcmp(s, "-") == 0) {
			pushback = c;
			return '-';
		}
		if (c != EOF)
			pushback = c;
		return NUMBER;

	}
}

