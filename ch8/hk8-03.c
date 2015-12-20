//8.3 請參考範例 5.5 寫一個程式計算 n 個數字之中有多少對數字互質，
//我們可將範例 5.5 改寫成一個函式，用以決定兩個數字是否互質，
//這樣可以加快程式開發的速度。
//輸入一行共有 n 個正整數。輸出是這 n 個正整數中有 多少對數字互質。
//參數規範: 0 < n <= 100

#include <stdio.h>
int gcd (int a, int b)
{
	int temp;
	while (a % b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}

int main(void)
{
	int n, array[100];
	int i, j, count = 0;
	while(scanf("%d", &(array[n])) != EOF)
		n++;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (gcd(array[i], array[j]) == 1) {
				count++;
			}
	printf("%d\n", count);
	return 0;
}
