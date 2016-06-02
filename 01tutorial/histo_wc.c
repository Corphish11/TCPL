/* wc.c - count character, word, line */
#include <stdio.h>

#define     IN      1
#define     OUT     0

#define CHAR_MAX    128
/* count lines, words, lines in input */
main()
{
    int i, j;
    int c;
    int nc[CHAR_MAX];

    for (i = 0; i < CHAR_MAX; ++i) {
        nc[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        nc[c]++;
    }

    for (i = 0; i < CHAR_MAX; ++i) {
        if (nc[i] != 0) {
            if (i == '\n')
                printf("\\n:");
            else if (i == '\t')
                printf("\\t:");
            else
                printf("%2c: ", i);

            for (j = 0; j < nc[i]; ++j) {
                putchar('|');
            }
            printf("%d\n", nc[i]);
        }
    }
}
