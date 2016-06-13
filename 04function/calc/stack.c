/* stack.c - stack operation */
#include "calc.h"

#define		MAXVAL	100	/* maximum depth of val stack */

static int sp = 0;			/* next free stack position */
static double val[MAXVAL];		/* value stack */

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

