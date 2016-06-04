/* lim.c - print ranges of char, short, int, long
   float, double */
#include <limits.h>
#include <float.h>
#include <stdio.h>


int
main()
{
	printf("CHAR_BIT: %d\n", CHAR_BIT);
	printf("CHAR_MAX: %d\n", CHAR_MAX);
	printf("CHAR_MIN: %d\n", CHAR_MIN);
	printf("INT_MAX: %d\n", INT_MAX);
	printf("INT_MIN: %d\n", INT_MIN);
	printf("LONG_MAX: %d\n", LONG_MAX);
	printf("LONG_MIN: %d\n", LONG_MIN);
	printf("SCHAR_MAX: %d\n", SCHAR_MAX);
	printf("SCHAR_MIN: %d\n", SCHAR_MIN);
	printf("SHRT_MAX: %d\n", SHRT_MAX);
	printf("SHRT_MIN: %d\n", SHRT_MIN);
	printf("UCHAR_MAX: %d\n", UCHAR_MAX);
	printf("UINT_MAX: %d\n", UINT_MAX);
	printf("USHRT_MAX: %d\n", USHRT_MAX);
	printf("ULONG_MAX: %d\n", ULONG_MAX);

	printf("\nFLT_MAX: %f\n", FLT_MAX);
	printf("FLT_MIN: %f\n", FLT_MIN);
	printf("FLT_DIG: %d\n", FLT_DIG);
	printf("DBL_MAX: %f\n", DBL_MAX);
	printf("DBL_MIN: %f\n", DBL_MIN);
	printf("DBL_DIG: %d\n", DBL_DIG);

	return 0;	
}
