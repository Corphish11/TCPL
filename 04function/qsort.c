/* qsort.c - quick sort algorithm */
#include <stdio.h>

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)		/* do nothing if array contains fewer than tow elements */
		return;
	swap(v, left, (left + right)/2);	/* move partition element */
	last = left;
	for (i = left + 1; i <= right; ++i)	/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);

	swap(v, left, last);			/* restore partition element */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);

}

void swap(int v[], int i, int j)
{
	int t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}


main()
{
	int i;
	int v[9] = {23, 23, 21, 1, 4, 98, 56, 22, 66};
	
	qsort(v, 0, 8);
	
	for (i = 0; i < 9; ++i) {
		printf("%d%c", v[i], i == 8 ? '\n': '\t');
	}
}
