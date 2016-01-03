/*
編寫一個程式計算每一個英文字出現的頻率。一個
英文字的定義是連續的字母。字母有區分大小寫，
所以 This 及 this 是不同的英文字。英文字的長度
為 n，不同英文字的個數為 m。
程式必須處理所有的輸入直到 EOF。輸出為所有英文
字及出現的次數。輸出的順序必然依照出現的次數排
序，出現次數少的英文字先輸出。如果出現次數一樣
多，則依照 strcmp 的順序排序。每一個英文字輸出
一行，每行先輸出英文字出現的次數，然後一個空格
，然後是英文字本身。
參數規範 0 < n <= 80, 0 < m <= 100
*/

#include <stdio.h>
#include <string.h>

int main (void)
{
	char s[80][101];
	char *ptrs[80], *temp;
	int count = 0, i, j;
	int s_count[80] = {0}, max_s_count = 0;
	
	//讀入字串
	while (scanf("%s", s[count]) != EOF && count < 80) {
		ptrs[count] = s[count];
		count++;
	}
	//按字母順序排序字串指標
	for (i = 0; i < count - 1; i++)
		for (j = i; j < count; j++)
			if (strcmp(ptrs[i], ptrs[j]) > 0) {
				temp = ptrs[i];
				ptrs[i] = ptrs[j];
				ptrs[j] = temp;
			}
	//計算單字個數
	for (i = 0; i < count;) {
		for (j = i + 1; j < count && strcmp(ptrs[i], ptrs[j]) == 0; j++);
		s_count[i] = j - i;
		max_s_count = (max_s_count > s_count[i]) ? max_s_count : s_count[i];
		i = j;
	}
	//先依單字個數在依照字串單字順序印出結果
	for (i = 1; i <= max_s_count; i++)
		for (j = 0; j < count; j++)
			if (s_count[j] == i) {
				printf("%d %s\n", i, ptrs[j]);
			}
	
	return 0;
}
