/* l80.c - print line longer than 80 char  */
#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE    80

int my_getline(char line[], int maxline);

main()
{
    int len;                    /* current line length */
    char line[MAXLINE];          /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > LONGLINE)
            printf(line);

    return 0;
}

/* getline: read a line into 's', return length */
int my_getline(char s[], int lim)
{
    int c, i;
    int len;

    for (i = 0; i < lim-1 && (c=getchar())!=EOF  && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    len = i;
    if (c != EOF && c != '\n')
        while ((c = getchar()) != EOF && c != '\n')
            len++;

    return len; 
}

