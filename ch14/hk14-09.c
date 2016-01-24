/*
請寫一個程式將一個正整數表示為金字塔數的和。第 i 個金字塔
數的定義是，1 * 1 + ... + i * i，所以第一個金字塔數是 1 ，
第二個金字塔數是 5，依此類推。現給定一個正整數 n，請將 n
表示為金字塔數的和。
參數規範: n < 10000000
*/

#include <stdio.h>

void pri_pry(int n)
{
	static int nth = 0;
	static int series[20] = {0};
	int sum_pry = 0;
	int i = 1;
	
	if (n == 0) {
		for (i = 0; i < nth; i++)
			sum_pry += series[i];
		printf("%d = ", sum_pry);
		
		for (i = 0; i < nth - 1; i++)
			printf("%d + ", series[i]);
		printf("%d\n", series[nth - 1]);
		return;
	}
	
	while (n >= sum_pry + i * i) {
		sum_pry += i * i;
		i++;
	}
	series[nth] = sum_pry;
	nth++;
	pri_pry(n - series[nth - 1]);
	
	return;
}

int main (void)
{
	int n;
	scanf("%d", &n);
	pri_pry(n);
	return 0;
}
