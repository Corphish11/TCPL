/* cp.c - copy standard input to standard output */
#include <stdio.h>

#define     NORMAL      0
#define     SPACING     1

/* copy input to output, 2nd version */
main()
{
    int c;
    int status;

    status = NORMAL;
    while ((c = getchar()) != EOF)
        if (c == ' ') {
            if (status != SPACING) {
                putchar(c);
                status = SPACING;
            }
        } else {
            putchar(c);
            status = NORMAL;
        }
}
