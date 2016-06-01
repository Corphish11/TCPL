/* lc.c - count lines from input  */
#include <stdio.h>

/* count lines */
main()
{
    double nl;
    int c;

    for (nl = 0; (c = getchar()) != EOF; )
        if (c == '\n')
            ++nl;
    printf("%.0f\n", nl);
}
