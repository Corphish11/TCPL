/* getch.c - get and unget a char */
#include "calc.h"

static int ungetch_char = -1;

int getch(void)		/* get a (possibly pushed back) character */
{
	int c;

	c = ungetch_char == -1 ? getchar() : ungetch_char;
	ungetch_char = -1;
	return c;
}

void ungetch(int c)	/* push character back on input */
{
	if (c != EOF)
		ungetch_char = c;
}
/*
void ungets(char s[])
{
	int i;

	for (i = strlen(s); i >= 0; --i)
		ungetch(s[i]);
}
*/
