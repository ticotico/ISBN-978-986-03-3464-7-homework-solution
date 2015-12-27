/*
寫一個程式將輸入全部小寫字母轉成大寫字母，全部大寫字母
轉成小寫字母，其餘字元不變，程式必須處理所有字元直到EOF
*/

#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c;
	while (scanf("%c", &c) != EOF) {
		if (isupper(c))
			printf("%c", tolower(c));
		else if (islower(c))
			printf("%c", toupper(c));
		else
			printf("%c", c);
	}
	return 0;
}
