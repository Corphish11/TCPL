/* check_error.c - check syntax error of unbalanced parentheses,
   brackets, and braces. */
#include <stdio.h>

#define		NORMAL		0
#define		DQUOTE_IN	1
#define		QUOTE_IN	2
#define		COMMENT_IN	3

int my_getchar(void);

int lineno = 1;
int colno = 0;

#define		MATCH_STACKSIZE		1024
char matchs[MATCH_STACKSIZE];
int stacktop = MATCH_STACKSIZE;

int
main()
{
	int c;
	int state;
	
	state = NORMAL;
	c = my_getchar();
	while (c != EOF) {
		if (state == NORMAL) {
			if (c == '\'') {
				state = QUOTE_IN;

			} else if (c == '\"') {
				state = DQUOTE_IN;

			} else if (c == '/') {
				c = my_getchar();
				if (c == '*')
					state = COMMENT_IN;
				else
					continue;

			} else if (c == '(' || c == '[' || c == '{') {
				--stacktop;
				if (stacktop < 0) {
					printf("Match stack overflow\n");
					return 1;
				}
				matchs[stacktop] = c;
				//printf("%c at %d,%d\n", c, lineno, colno);

			} else if (c == ')' || c == ']' || c == '}') {
				if (stacktop < MATCH_STACKSIZE && 
					((matchs[stacktop] == '(' && c == ')')
					|| (matchs[stacktop] == '[' && c == ']')
					|| (matchs[stacktop] == '{' && c == '}'))) {
					++stacktop;

					//printf("%c at %d,%d\n", c, lineno, colno);
				} else {
					printf("'%c' at %d,%d not matchs.\n", c, lineno, colno);
					return 2;
				}
			}
		} else if (state == COMMENT_IN) {
			if (c == '*') {
				c = my_getchar();
				if (c == '/')
					state = NORMAL;
				else
					continue;
			}
		} else if (state == DQUOTE_IN) {
			if (c == '\\') {
				c = my_getchar();
			} else if (c == '\"')
				state = NORMAL;
			
		} else if (state == QUOTE_IN) {
			if (c == '\\') {
				c = my_getchar();
			} else if (c == '\'')
				state = NORMAL;
			
		}
		c = my_getchar();
	}
	return 0;
}


int 
my_getchar()
{
	int c;

	c = getchar();

	if (c == '\n') {
		++lineno;
		colno = 0;
	} else
		++colno;

	return c;
}
