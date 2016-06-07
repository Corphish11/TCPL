/* literal.c - print lines match the literal */
#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

main()
{
	char line[MAXLINE];          /* current input line */
	int found = 0;

	while (my_getline(line, MAXLINE) != 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

