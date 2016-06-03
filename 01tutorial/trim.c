/* trim.c - remove empty line, and trailing space and tabs
 * of each line.  */
#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE    80

int my_getline(char line[], int maxline);
char *trim_tail(char s[], int len);

main()
{
    int len;                    /* current line length */
    char line[MAXLINE];          /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0) {
        trim_tail(line, len);
        if (line[0] != '\n')
            printf(line);
    }

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

/* trim_tail: remove trailing space and tabs of each line,
   assume the line is with a '\n'  */
char * trim_tail(char s[], int len)
{
    int tail;

    tail = len - 1; 
    for (tail = len - 1; 
        tail >= 0 && s[tail] == '\t' && s[tail] == ' ';
         --tail)
        ;

    s[++tail] = '\n';
    s[tail] = '\0';

    return s;
}
