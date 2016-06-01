/* fah2cel2.c - print Fahrenheit-Celsius table, float version  */ 
#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; float version  */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;          /* lower limit of temperature table */
    upper = 300;        /* upper limit */
    step = 20;          /* step size */

   celsius = lower;
    printf("%3s %6s\n", "Cel", "Fah");
    while (celsius <= upper) {
        /* celsius = 5.0 / 9.0 * (fahr-32.0); */
        fahr =  celsius / 5.0 * 9.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
