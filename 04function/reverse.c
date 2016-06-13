/* reverse.c - reverse array recursively */
#include <stdio.h>


void swap(int v[], int i, int j)
{
	int t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void reverse(int v[], int left, int right)
{
	if (left < right) {
		swap(v, left, right);
		reverse(v, left+1, right-1);
	}
}

main()
{
	int i;
	int v[9] = {23, 23, 21, 1, 4, 98, 56, 22, 66};

	printf("%s", "original: ");
	for (i = 0; i < 9; ++i) {
		printf("%d%c", v[i], i == 8 ? '\n': '\t');
	}

	reverse(v, 0, 8);
	
	for (i = 0; i < 9; ++i) {
		printf("%d%c", v[i], i == 8 ? '\n': '\t');
	}
}
