/* remove_comment.c - remove comments */
#include <stdio.h>

#define		NORMAL		0
#define		DQUOTE_IN	1
#define		QUOTE_IN	2
#define		COMMENT_IN	3

int
main()
{
	int c;
	int state;
	
	state = NORMAL;
	while ((c = getchar()) != EOF) {
		if (state == NORMAL) {
			if (c == '\'') {
				state = QUOTE_IN;
				putchar(c);
			} else if (c == '\"') {
				state = DQUOTE_IN;
				putchar(c);
			} else if (c == '/') {
				c = getchar();
				if (c == '*')
					state = COMMENT_IN;
				else {
					putchar('/');
					putchar(c);
				}
			} else
				putchar(c);
		} else if (state == COMMENT_IN) {
			if (c == '*') {
				c = getchar();
				if (c == '/')
					state = NORMAL;
			}
		} else if (state == DQUOTE_IN) {
			if (c == '\\') {
				putchar(c);
				c = getchar();
			} else if (c == '\"')
				state = NORMAL;
			
			putchar(c);
		} else if (state == QUOTE_IN) {
			if (c == '\\') {
				putchar(c);
				c = getchar();
			} else if (c == '\'')
				state = NORMAL;
			
			putchar(c);

		}
	}
	return 0;
}
