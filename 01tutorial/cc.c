/* cc.c - count character from input  */
#include <stdio.h>

/* count character, 1st version */
main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
