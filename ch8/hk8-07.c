//寫一個程式計算從 n 個不同物品中取 m 個
//不同物品的方法總數。我們可以先寫一個計算
//c m 取 n 的函式，之後計算 sigma 即可。
//輸入只有一行，n 及 m 。輸出是 n 個不同物品中取
//不超過 m 個物品的方法總數。
//參數規範 0 < n < 15, 0 < m <= n

#include <stdio.h>
int c_n_get_m (int n, int m)
{
	int result = 1, i;
	for (i = n; i > (n - m); i--) 
		result *= i;
	for (i = 1; i <= m; i++)
		result /= i;
	return result;
}

int main(void)
{
	int n, m, i, ans = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i <= m; i++)
		ans += c_n_get_m(n, i);
	printf("%d\n", ans);
	return 0;
}
