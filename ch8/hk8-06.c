//寫一個程式計算統一發票獎金，統一發票收執聯是八位數
//每一期會有三個特獎號碼及三個頭獎號碼。
//獎金的算法如下

//收執聯 8 位數號碼與特獎號碼相同者為特獎 200 萬元
//收執聯 8 位數號碼與頭獎號碼相同者為頭獎 20 萬元
//收執聯末 7 位數號碼與頭獎號碼相同者為二獎 4 萬元
//收執聯末 6 位數號碼與頭獎號碼相同者為三獎 1 萬元
//收執聯末 5 位數號碼與頭獎號碼相同者為四獎 4 千元
//收執聯末 4 位數號碼與頭獎號碼相同者為五獎 1 千元
//收執聯末 3 位數號碼與頭獎號碼相同者為六獎 2 百元

//輸入的前三行為特獎號碼，後三行為頭獎號碼
//之後每一行為我們收集的發票收執聯號碼。
//程式必須處理所有的輸入直到 EOF (end of file)，
//輸出為所得獎金總額

#include <stdio.h>
int get_price(int special[3], int head[3], int num)
{
	int i, j, power = 100000000;
	int head_price[7] = {0, 200000, 40000, 10000, 4000, 1000, 200};
	for (i = 0; i < 3; i++)
		if (num == special[i])
			return 200000;
	
	for (i = 0; i < 3; i++) {
		for (j = 1, power = 100000000; j <= 6; j++, power /= 10) {
			if (num % power == head[i] % power)
				return head_price[j];
		}
	}
	
	return 0;
}

int main(void)
{
	int head_num[3], special_num[3];
	int input, i, price = 0;
	
	for (i = 0; i < 3; i++)
		scanf("%d", &(special_num[i]));
	for (i = 0; i < 3; i++)
		scanf("%d", &(head_num[i]));
	
	while (scanf("%d", &input) != EOF) {
		price += get_price(special_num, head_num, input);
	}
	
	printf("%d\n", price);
	return 0;
}
