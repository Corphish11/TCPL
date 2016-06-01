/* fah2cel2.c - print Fahrenheit-Celsius table, float version  */ 
#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; float version  */
main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, 5.0 / 9.0 * (fahr-32.0));
    }
}
