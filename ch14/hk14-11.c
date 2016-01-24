/*
假設有 n 個物件和一個背包。每個物件有一個重量 w 和價值 v，
而背包有總重量限制 W。如何選擇物件放入背包中，使得放入背包
的物件總重量限制 W，但放入背包的物件總價值最大?
輸入第一行輸入物件個數 n 與背包重量限制 W。以下 n 行一行代表
一個物件。一個物件有重量 w 與價值 n。輸出是可放入背包的最大
物件總價值。
參數規範: 0 < n < 20, 0 < W <= 10000, 0 < w, v <= 1000
*/

#include <stdio.h>

int max_value(int n, int W, int w[], int v[])
{
	int result;
	int a, b;
	
	if (n == 0)
		return 0;
	
	//place nth item
	if (W - w[n - 1] >= 0)
		a = v[n - 1] + max_value(n - 1, W - w[n - 1], w, v);
	else
		a = max_value(n - 1, W, w, v);
	
	//not place nth item
	b = max_value(n - 1, W, w, v);
	
	result = (a > b) ? a : b;
	
	return result;
}

int main (void)
{
	int n, W;
	int w[20], v[20];
	int i;
	
	scanf("%d%d", &n, &W);
	for (i = 0; i < n; i++)
		scanf("%d%d", &w[i], &v[i]);
	printf("%d\n", max_value(n, W, w, v));
	
	return 0;
}
