/*
編寫一個程式將兩個正整數相加，而這兩個整數可以多達
n 位。注意不能使用 int 來儲存這兩個正整數，因為一個
int 只有四個位元組，最大只能存到約 10 位數。程式必
須用兩個字串儲存兩個超長正整數，並作加法運算。
參數規範 0 < n <= 100
*/

#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[101], s2[101], s3[103];
	char temp;
	int len1, len2, len3;
	int i, a, b, add_one;
	scanf("%s", s1);
	scanf("%s", s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	
	for (i = 0; i < len1 / 2; i++) {
		temp = s1[i];
		s1[i] = s1[len1 - 1 - i];
		s1[len1 - 1 - i] = temp;
	}
	for (i = 0; i < len2 / 2; i++) {
		temp = s2[i];
		s2[i] = s2[len2 - 1 - i];
		s2[len2 - 1 - i] = temp;
	}
	
	for (i = len1; i < len2; i++)
		s1[i] = '0';
	s1[i] = '\0';
	for (i = len2; i < len1; i++)
		s2[i] = '0';
	s2[i] = '\0';
	
	a = s1[0] - '0';
	b = s2[0] - '0';
	add_one = (a + b) / 10;
	s3[0] = (a + b) % 10 + '0';
	
	for (i = 1; i < ((len1 > len2) ? len1 : len2); i++) {
		a = s1[i] - '0';
		b = s2[i] - '0';
		s3[i] = (a + b) % 10 + add_one + '0';
		add_one = (a + b) / 10;
	}
	if ((a + b) / 10 != 0) {
		s3[i] = (a + b) / 10 + '0';
		i++;
	}	
	s3[i] = '\0';
	len3 = strlen(s3);
	
	for (i = 0; i < len3 / 2; i++) {
		temp = s3[i];
		s3[i] = s3[len3 - 1 - i];
		s3[len3 - 1 - i] = temp;
	}
	printf("%s\n", s3);
	return 0;
}
