/* strcat.c - append a string to another string */
#include <stdio.h>

void mstrcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

main()
{

	char s[100] = "abcde";
	char t[100] = "fghi";
	mstrcat(s, t);
	printf("%s\n", s);
}
