//寫一個程式以遞迴方式計算從1 到 N 的平方和

#include <stdio.h>

int square_sum (int i)
{
	if (i == 1)
		return 1;
	else
		return square_sum(i - 1) + i * i;
}

int main (void)
{
	int i, result;
	scanf("%d", &i);
	printf("%d\n", square_sum(i));
	return 0;
}
