/* qsortlines.c - quick sort lines */
#include <stdio.h>
#include <string.h>

void qsort(char * v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)		/* do nothing if array contains fewer than tow elements */
		return;
	swap(v, left, (left + right)/2);	/* move partition element */
	last = left;
	for (i = left + 1; i <= right; ++i)	/* partition */
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);			/* restore partition element */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);

}

void swap(char * v[], int i, int j)
{
	char* t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

