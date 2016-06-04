/* htoi.c - hexadecimal string to numeric */
#include <ctype.h>
#include <stdio.h>

unsigned int htoi(char s[]);

int
main()
{
	char h[] = "0xFb0E12";
	printf("%s: %u\n", h, htoi(h));
	return 0;
}


unsigned int
htoi(char s[])
{
	int h, i;


	if (s[0] == 0 || s[1] == 0)
		return 0;

	if (!(s[0] == '0' && toupper(s[1]) == 'X'))
		return 0;

	h = 0;
	i = 2;
	while (isxdigit(s[i])) {
		int d = toupper(s[i]);
		if (isdigit(d))
			h = h * 16 + (d - '0');
		else
			h = h * 16 + (d - 'A' + 10);

		++i;
	}
	return h;

}
