#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
main(int argc, char *argv[])
{
    int c;
    int islower;
    int len = strlen(argv[0]);

    islower = len-5 >= 0 && strcmp(&argv[0][len-5], "lower") == 0;

    //printf("%s\n", argv[0]);

    while ((c = getchar()) != EOF) 
        putchar(islower ? tolower(c) : toupper(c));

    return 0;
}
