/* main.c - Reverse Polish calculator */
#include <stdio.h>
#include <stdlib.h>			/* for atof() */
#include <string.h>
#include <math.h>
#include "calc.h"

#define		MAXOP	100		/* max size of operand of operator */

double var;

/* reverse Polish calculator */
main()
{
	int type;
	double op2, op3;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case FUNC:
			if (strcmp("sin", &s[1]) == 0)
				push(sin(pop()));
			else if (strcmp("exp", &s[1]) == 0)
				push(exp(pop()));
			else if (strcmp("pow", &s[1]) == 0) {
				op2 = pop();
				push(pow(pop(), op2));
			}
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
		case 'p':		/* print top stack number */
			printf("\t%.8g\n", var = peek());
			break;
		case 'v':
			printf("\t%.8g\n", var);
			break;
		case 'x':
			exchg();
			break;	
		case 'c':
			clear();
			break;		
		case '\n':
			//printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return 0;
}


