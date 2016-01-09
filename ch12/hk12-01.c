//在假設位數 n 不超過 18 的情況下重作作業 10.6。
//此時由於位數限制，我們可以用適當的資料類別簡單
//完成餘數計算。

#include <stdio.h>

int main(void)
{
	long long int lli;
	while(scanf("%lld", &lli) != EOF) {
		printf("%s\n", (lli % 2 == 0) ? "yes" : "no");
		printf("%s\n", (lli % 3 == 0) ? "yes" : "no");
		printf("%s\n", (lli % 5 == 0) ? "yes" : "no");
		printf("%s\n", (lli % 11 == 0) ? "yes" : "no");
	}
	return 0;
}
