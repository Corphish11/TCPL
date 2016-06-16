/* qsort.c - quick sort algorithm */
void qsort(void * v[], int left, int right,
	int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)		/* do nothing if array contains fewer than tow elements */
		return;
	swap(v, left, (left + right)/2);	/* move partition element */
	last = left;
	for (i = left + 1; i <= right; ++i)	/* partition */
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);			/* restore partition element */
	qsort(v, left, last - 1, comp);
	qsort(v, last + 1, right, comp);

}

void swap(void * v[], int i, int j)
{
	void* t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

