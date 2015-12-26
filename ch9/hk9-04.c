/*
寫一個程式計算函式 f(x,y) = 4x - 6y並求最大值
*/

#include <stdio.h>
#define N 256

int eval_f(int *iptr[], int n, int *index)
{
	int count;
	int max_value = 4 * (*iptr[0]) - 6 * (*(iptr[0] + 1));
	int i;
	*index = 0;
	
	for (i = 1; i < n; i++) {
		count = 4 * (*iptr[i]) - 6 * (*(iptr[i] + 1));
		if (count >= max_value) {
			max_value = count;
			*index = i;
		}
	}
	
	return max_value;
}

int main(void)
{
	int n = 0;
	int x, y;
	int xy[2 * N];
	int xy_n = 0;
	int max, max_index;
	int *iptr[N];
	
	while (scanf("%d%d", &x, &y) != EOF) {
		iptr[n] = &(xy[xy_n]);
		n++;
		xy[xy_n] = x;
		xy_n++;
		xy[xy_n] = y;
		xy_n++;
	}
	
	max = eval_f(iptr, n, &max_index);
	printf("%d %d\n", max, max_index);
	
	return 0;
}
