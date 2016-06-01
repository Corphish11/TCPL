/* fah2cel4.c - print Fahrenheit-Celsius table, reversed for version  */ 
#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; reversed for version  */
main()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, 5.0 / 9.0 * (fahr-32.0));
    }
}
