/* strend.c - check if a string is at the end of another string */
#include <stdio.h>
#include <string.h>

int mstrend(char *s, char *t)
{
	int ns, nt;
	ns = strlen(s);
	nt = strlen(t);

	if (nt > ns)
		return 0;

	s += ns - nt;
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 1;
	
	return 0;
}

main()
{

	char s[100] = "abcde";
	char t[100] = "cde";
	printf("%d\n", mstrend(s, t));
}
