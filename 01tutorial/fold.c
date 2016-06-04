/* fold.c - fold long line to multiple lines */

#include <stdio.h>

#define		MAXWORD		80
#define		MAXCOL		80
#define		TABSTOP		8

int readword(char s[], int lim);

int last_char;

int
main()
{
	int len;
	int p;
	char s[MAXWORD];
	int c;

	p = 0;
	
	len = readword(s, MAXWORD);
	while (last_char != EOF) {
		if (len == 0) {
			c = last_char;
			if (c == ' ') {
				p++;
				if (p > MAXCOL-1) {
					putchar('\n');
					p = 1;
				}
				putchar(c);
			} else if (c == '\t') {
				p = (p / TABSTOP + 1) * TABSTOP;
				if (p > MAXCOL - 1) {
					putchar('\n');
					p = TABSTOP;
				}
				putchar(c);
			} else if (c == '\n') {
				p = 0;
				putchar(c);
			}

			len = readword(s, MAXWORD);
		} else {
			p += len;
			if (p > MAXCOL - 1) {
				putchar('\n');
				p = len;
			}
			printf("%s", s);
	
			len = 0;
		}

		//printf("\n==[%s]==\n", s);
	}
}

/* readword: read a word, and return the length,
             if the next char is a white space or EOF,
             put the char into 'last_char' and return 0.  */
int readword(char s[], int lim)
{
	int p = 0;

	while (((last_char = getchar()) != EOF)
			&& (last_char != ' ')
			&& (last_char != '\t')
			&& (last_char != '\n')
			&& (p < lim - 1))		
		s[p++] = last_char;

	s[p] = '\0';
	return p;
}
