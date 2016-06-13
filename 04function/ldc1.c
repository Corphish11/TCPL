/* ldc.c - Reverse Polish calculator */
#include <stdio.h>
#include <stdlib.h>			/* for atof() */
#include <string.h>
#include <math.h>

#define		MAXOP	100		/* max size of operand of operator */
#define		NUMBER	'0'		/* signal that a number was found */
#define		FUNC	'\''		/* signal that a function was found */

#define 	LINESIZE	1000
char line[LINESIZE];
int line_pos;

int my_getline(char s[], int lim);

int getop(char []);
void push(double);
double pop(void);
void clear();
double peek();
void exchg();


double var;

/* reverse Polish calculator */
main()
{
	int type;
	double op2, op3;
	char s[MAXOP];

	my_getline(line, LINESIZE);

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

/* stack.c - stack operation */
#define		MAXVAL	100	/* maximum depth of val stack */

int sp = 0;			/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push 'f' onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* clear: clear stack */
void clear()
{
	sp = 0;
}
/* peek: peek top stack number */
double peek()
{
	if (sp > 0)
		return val[sp-1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
/* exchg: exchange the top 1st, 2nd numbers */
void exchg()
{
	double t;
	if (sp >= 2) {
		t = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = t;
	} else
		printf("error: # of stack numbers is less than 2\n");
}

/* getop.c - get next operator */
#include <ctype.h>

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	if (line[0] == '\0')
		return EOF;

	while ((s[0] = c = line[line_pos++]) == ' ' || c == '\t')
		;

	if (c == '\n') {
		my_getline(line, LINESIZE);
		line_pos = 0;
	}

	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-' && c != '\'')
		return c;		/* not a number */

	i = 0;

	if (c == '\'') {		/* function operator */
		while (isalnum((s[++i] = c = line[line_pos++])))
			;
		if (c != EOF)
			--line_pos;
		s[i] = '\0';
		return FUNC;
	} else {

		if (c == '-') {
			s[1] = c = line[line_pos++];
			i = 1;
		}

		if (isdigit(c))			/* collect integer part */
			while (isdigit(s[++i] = c = line[line_pos++]))
			;
		if (c == '.')			/* colloct fractional part */
			while (isdigit(s[++i] = c = line[line_pos++]))
			;

		s[i] = '\0';

		/* '-' is not unary operator if the following character is not digit */
		if (strcmp(s, "-") == 0) {
			--line_pos;
			return '-';
		}
		if (c != EOF)
			--line_pos;
		return NUMBER;

	}
}

