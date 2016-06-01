/* cp.c - copy standard input to standard output */
#include <stdio.h>

/* copy input to output, 2nd version */
main()
{
    int c;

    while ((c = getchar()) != EOF)
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\n')
            printf("\\n");
        else
            putchar(c);
}
