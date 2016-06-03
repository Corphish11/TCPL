/* entab.c - replace blanks by tabs 
 * Idea: View each screen row as strips whin which there are TABSTOP positions */
#include <stdio.h>

#define		TABSTOP		8

main()
{
	int c;
	int pos;		/* (pos % TABSTOP) is the index whin each strips */
	int nblank;

	pos = 0;
	nblank = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++nblank;
			++pos;
		} else if (c == '\t') {
			nblank = 0;
			/* input is divided into TABSTOP chars segment */
			pos = 0;
			putchar(c);
		} else {
			/* print stored blanks */
			while (nblank > 0) {
				putchar(' ');
				--nblank;
			}

			putchar(c);
			if (c == '\n')
				pos = 0;	
			else
				++pos;
		}

		/* if reach tab stop and some blank is stored */
		if ((nblank > 0) && (pos % TABSTOP == 0)) {
			putchar('\t');
			nblank = 0;
		}

        
	}
}
