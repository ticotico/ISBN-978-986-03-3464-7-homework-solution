//寫一個程式計算 a / b + c / d，並將答案化簡為最簡分數，
//我們可以將範例 5.5 改寫成一個函式，用以決定兩個數字的
//最小公因數，這樣可以用來化簡最後的答案。
//輸入為 a, b, c, d。輸出為a / b + c / d，分子在前，
//分母在後。
//參數規範 0 < a, b, c, d <= 1000

#include <stdio.h>
int lcm (int p, int q)
{
	int a = p, b = q, temp;
	while(p % q != 0) {
		temp = p%q;
		p = q;
		q = temp;
	}
	return a * b / q;
}

int main(void)
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	f = lcm(b, d);
	e = a * f / b + c * f / d;
	printf("%d %d\n", e, f);
	return 0;
}
