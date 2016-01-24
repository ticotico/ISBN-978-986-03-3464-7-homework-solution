/*
寫一個程式計算從一個矩陣的角落走到對角有幾種方法。假設矩陣
有 n 行 m 列，我們從左下角出發要移動到右上角，而且只能夠向
東或向北兩個方向每次移動一格。請計算可以走的方法數量。輸入
為 n 及 m ，輸出為可以走的方法數目。
參數規範: 0 < n,m <= 15
*/

#include <stdio.h>

int ways_array (int m, int n)
{
	if (m == 1 || n == 1) {
		printf("call ways_array(%d, %d)\n", m, n);
		return 1;
	}
	return ways_array(m - 1, n) + ways_array(m, n - 1);
}

int main (void)
{
	int i, j, result;
	scanf("%d%d", &i, &j);
	printf("%d\n", ways_array(i, j));
	return 0;
}
