#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int m;
typedef struct {
	int **pt_data;
	int size;
	int member;
	int col;
}GroupInt;

void init_Group (GroupInt *gi, int col)
{
	gi->pt_data = (int **) malloc (sizeof(int *));
	gi->member = 0;
	gi->size = 1;
	gi->col = col;
}

void print_Group (GroupInt *gi)
{
	int i, j;
	int row = gi->member;
	int col = gi->col;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("%d ", gi->pt_data[i][j]);
		putchar('\n');
	}
}


void delete_Group (GroupInt *gi)
{
	int i, row = gi->member;
	for (i = 0; i < row; i++)
		free(gi->pt_data[i]);
	free(gi->pt_data);
	gi->size = 1;
	gi->member = 0;
}

GroupInt *add_Array (GroupInt *gi, int *array)
{
	int **new_ptr;
	int new_size;;
	if (gi->member >= gi->size) {
		new_size = gi->size * 2;
		new_ptr = (int **) malloc (sizeof(int *) * new_size);
		assert(new_ptr != NULL);
		memcpy(new_ptr, gi->pt_data, sizeof(int *) * gi->size);
		free(gi->pt_data);
		gi->pt_data = new_ptr;
		gi->size = new_size;
	}
	gi->pt_data[gi->member++] = array;
}

int comp_GroupInt (const void *data1, const void *data2)
{
	int *ptr1 = (int *) data1;
	int *ptr2 = (int *) data2;
	int i;
	for (i = 0; i < m; i++)
		if (ptr1[i] != ptr2[i])
			return ptr1[i] - ptr2[i];
	return 0;
}

int main (void)
{
	int n;
	int i, j;
	int row;
	int *array;
	GroupInt gi;
	scanf("%d%d", &n, &m);
	assert(n % m == 0);
	row = n / m;
	
	init_Group(&gi, m);
	
	for (i = 0; i < row; i++) {
		array = (int *) malloc (sizeof(int) * m);
		assert(array != NULL);
		for (j = 0; j < m; j++)
			scanf("%d", &(array[j]));
		add_Array(&gi, array);
	}
	
	qsort(gi.pt_data, row, sizeof(int *), comp_GroupInt);
	print_Group(&gi);
	delete_Group(&gi);
	return 0;
}
