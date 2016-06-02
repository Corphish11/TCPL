/* wc.c - count character, word, line */
#include <stdio.h>

#define     IN      1
#define     OUT     0

#define     WORD_LEN    20
/* count lines, words, lines in input */
main()
{
    int i, j;
    int c, len, state;
    int nlen[WORD_LEN];

    state = OUT;
    len = 0;
    for (i = 0; i < WORD_LEN; ++i) {
        nlen[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                ++nlen[len];
                len = 0;
            }
        } else {
            state = IN;
            ++len;
        }
    }

    for (i = 1; i < WORD_LEN; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < nlen[i]; ++j) {
            putchar('|');
        }
        printf("%d\n", nlen[i]);
    }
}
