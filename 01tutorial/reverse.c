/* reverse.c - reverse each line */ 
#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
char *reverse(char line[], int len);

main()
{
    int len;                    /* current line length */
    char line[MAXLINE];          /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0)
        printf(reverse(line, len));

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

/* reverse: reverse chars  */
char *reverse(char s[], int len)
{
    int i;
    int c;

    for (i = 0; i < (len - 1)/2; i++) {
        c = s[i];
        s[i] = s[len-2-i];
        s[len-2-i] = c;
    }
        
    return s;
}
