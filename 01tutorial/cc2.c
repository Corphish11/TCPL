/* cc2.c - count character from input  */
#include <stdio.h>

/* count character, 2nd version */
main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
