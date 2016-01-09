/*
在假設位數 n 不超過 18 的情況下重作作業 11.3。
此時由於位數限制，我們可以用適當的資料類別完成
加法。
*/
#include <stdio.h>

int main (void)
{
	long long int a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", a + b);
	return 0;
}
