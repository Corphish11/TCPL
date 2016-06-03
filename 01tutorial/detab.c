/* detab.c - replace tab by propriate number space */
#include <stdio.h>

#define 	TABSTOP		8
main()
{
    int c;
    int i, pos;

    pos = 0;
    c = getchar();
    while (c != EOF) {
        if (c != '\t') {
            putchar(c);
            ++pos;
        } else {
            i = pos;
            /* pos =  next tab stop */
            pos = (pos / TABSTOP + 1) * TABSTOP;
            for (; i < pos; ++i)
                putchar(' ');
        }
        
        c = getchar();
    }
}
