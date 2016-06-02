/* fah2cel6.c - print Fahrenheit-Celsius table, function version  */ 
#include <stdio.h>

#define     LOWER   0           /* lower limit of table */
#define     UPPER   300         /* upper limit */
#define     STEP   20          /* step size */

float celsius(int fahr);

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300;  */
main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER ; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, celsius(fahr));
    }
}

/* celsius: convert termperature from fahrenheit to celsius */
float celsius(int fahr)
{
    return (5.0 / 9.0 * (fahr-32.0));
}
