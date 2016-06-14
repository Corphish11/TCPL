/* find.c - print lines that match pattern from 1st arg */
#include <stdio.h>
#include <string.h>

#define		MAXLINE		1000

int my_getline(char *line, int lim);

main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0, lineno = 0;
	int except = 0, number = 0;
	int c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("Usage: find -x -n pattern\n");
				argc = 0;
				found = -1;
				break;
			}
	if (argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (my_getline(line, MAXLINE) > 0) {
			lineno++;
			if ((strstr(line, *argv) != NULL) != except) {
				if (number)
					printf("%d:", lineno);
				printf("%s", line);
				found++;
			}
		}

	return found;
}
