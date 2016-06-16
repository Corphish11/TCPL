/* sort.c - sort lines */
#include <stdio.h>
#include <string.h>

#define MAXLINES	100	/* max # lines to be sorted */
char *lineptr[MAXLINES];	/* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
	int (*comp)(void *, void *));
void reverse(void *v[], int n);
int numcmp(const char *, const char *);

/* sort input lines */
main(int argc, char *argv[])
{
	int nlines;		/* number of input lines read */
	int numeric = 0, rev = 0, ignorecase = 0;
	int c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'r':
				rev = 1;
				break;
			case 'n':
				numeric = 1;
				break;
			case 'f':
				ignorecase = 1;
				break;
			default:
				printf("sort: illegal options %c\n", c);
				return 1;
			}

//	printf("reverse %d\n", rev);
//	printf("numeric %d\n", numeric);

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines-1,
			(int (*)(void *, void *))(numeric ? numcmp : (ignorecase ? strcasecmp : strcmp)));

		if (rev)
			reverse((void **)lineptr, nlines);

		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}

#define		MAXLEN		1000
int my_getline(char *, int);
char *alloc(int);
/* realines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';	/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", *lineptr++);
}

