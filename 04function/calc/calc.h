/* calc.h - the only one header file for reverse polish cacculator */
#include <stdio.h>
#define		NUMBER	'0'		/* signal that a number was found */
#define		FUNC	'\''		/* signal that a function was found */

int getop(char []);
void push(double);
double pop(void);
void clear();
double peek();
void exchg();

int getch(void);
void ungetch(int c);
