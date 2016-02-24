#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int m;
int comp_int_array(const void *array1, const void *array2)
{
	int i;
	int *ptr1 = (int *) array1;
	int *ptr2 = (int *) array2;
	for (i = 0; i < m; i++) {
		//printf("%d %d\n", ptr1[i], ptr2[i]);
		if (ptr1[i] < ptr2[i])
			return -1;
		if (ptr1[i] > ptr2[i])
			return 1;
	}
	return 0;
}

int main (void)
{
	int i, j;
	int n;
	int *a1d;
	int **a2d;
	int row;
	scanf("%d%d", &n, &m);
	assert(n % m == 0);
	row = n / m;
	a1d = (int *) malloc (sizeof(int) * n);
	assert(a1d != NULL);
	a2d = (int **) malloc(sizeof(int *) * row);
	assert(a2d != NULL);
	
	for (i = 0; i < n; i++)
		scanf("%d", &a1d[i]);
	
	for (i = 0; i < row; i++)
		a2d[i] = &a1d[i * m];
	
	qsort(a1d, row, m * sizeof(int), comp_int_array);
	
	for (i = 0; i < row; i++) {
		for (j = 0; j < m; j++)
			printf("%d ", a2d[i][j]);
		putchar('\n');
	}
	
	free(a2d);
	free(a1d);
	return 0;
}
