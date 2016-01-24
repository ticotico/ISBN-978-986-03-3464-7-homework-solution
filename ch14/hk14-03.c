/*
同上題，寫一個程式計算從一個矩陣的角落走到對角有幾種方法，
只是現在有的矩陣格子是不能走的。輸入的第一行為 n 及 m ，以
下 n 行每行有 m 個元素，不能走的格子以 0 表示，可以走的格子
以 1 表示。輸出是可以走的方法數量。
參數規範: 0 < n,m <= 15
*/

#include <stdio.h>

int how_many_ways (int m, int n, int array[20][20])
{
	if (array[m][n] == 0)
		return 0;
	if (m == 0 && n == 0)
		return 1;
	if (m == 0)
		return how_many_ways(m, n - 1, array);
	if (n == 0)
		return how_many_ways(m - 1, n, array);
	
	return how_many_ways(m - 1, n, array) + how_many_ways(m, n - 1, array);
}

int main(void)
{
	int m, n;
	int i, j;
	int array[20][20];
	
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &(array[m - i - 1][j]));
		
	printf("%d\n", how_many_ways(m - 1, n - 1, array));
	return 0;
}
