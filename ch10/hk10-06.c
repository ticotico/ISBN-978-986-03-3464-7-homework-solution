/*
寫一個程式決定一個 n 位正整數是否能被2、3、5、11整除。
輸入為ㄧ個 n 位正整數。輸出有四行，分別代表是否為2、3
、5、11的倍數。若是則輸出 yes，否則輸出 no。
參數規範: 0 < n <= 1000
*/
#include <stdio.h>
int main(void)
{
	int is_2 = 0, is_3 = 0, is_5 = 0, is_11 = 0;
	int i = -1;
	char c;
	while (scanf("%c", &c) != EOF && c != '\n') {
		i *= -1;
		is_2 = c - '0';
		is_3 += c - '0';
		is_5 = c - '0';
		is_11 += i * (c - '0');
	}
	
	printf("%s\n", (is_2 % 2 == 0) ? "yes" : "no");
	printf("%s\n", (is_3 % 3 == 0) ? "yes" : "no");
	printf("%s\n", (is_5 % 5 == 0) ? "yes" : "no");
	printf("%s\n", (is_11 % 11 == 0) ? "yes" : "no");
	return 0;
}
