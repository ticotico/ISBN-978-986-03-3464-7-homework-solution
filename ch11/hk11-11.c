/*
編寫一個程式判定字串代表的資料類別。判定的規則如下，
1. 如果字串只由數字及最前面可有可無的正負號構成，即為整數。
2. 如果字串只由數字、一個小數點及最前面可有可無的正負號構成
，則為浮點數。注意小數點的前後至少要有一個數字。
3.如果不符合以上兩個條件則為字串。
*/

#include <stdio.h>
#include <ctype.h>

char type_of(char *s)
{
	char *ptr = s;
	char dot = 0;
	if((isdigit(s[0]) || s[0] == '+' || s[0] == '-' || s[0] == '.') == 0)
		return 2;
	ptr++;
	
	while (*ptr != '\0') {
		if ((isdigit(*ptr) || *ptr == '.') == 0)
			return 2;
		if (*ptr == '.') {
			if (dot == 0)
				dot = 1;
			else
				return 2;
		}
		ptr++;
	}
	
	if (*(ptr - 1) == '.')
		return 2;
	
	if (dot == 0)
		return 0;
	else if (dot == 1)
		return 1;
	else
		return -1;
	
}

int main (void)
{
	char type; //0: int, 1: float, 2: string
	char buf[64];
	while (scanf("%s", buf) != EOF) {
		type = type_of(buf);
		switch(type) {
			case 0:
				printf("int\n");
				break;
			case 1:
				printf("float\n");
				break;
			case 2:
				printf("string\n");
				break;
			default:
			printf("Error\n");
		}
	}
	
	return 0;
}
