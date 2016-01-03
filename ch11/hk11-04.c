/*
寫一個程式判斷兩個字是否相似，兩個字若為相似，
則下列兩個條件其中一個為真。
1. 兩個字長度相同，且如果我們交換一個字中的兩
個連續字元，我們可以得到另一個字。例如 best 和
bets 為相似，因為如果我們交換 best 中的 st ，
我們可以得到 bets。
2. 兩個字串長度差一，且如果我們刪除一個字中的一
個字元，我們可以得到另一個字，例如 best 和 bet 
為相似，因為如果我們刪除 best 中的 s，我們可以得
到 bet。
輸入每一行有兩個字要比對。程式必須處理所有的輸入
直到 EOF，字的長度限制為 n。如果一對字串相似，則
輸出 yes，否則輸出 no。
參數規範 0 < n <= 80
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[81], s2[81];
	char *ptr1, *ptr2;
	
	while (scanf("%s%s", s1, s2) != EOF) {
		ptr1 = s1;
		ptr2 = s2;
		while (*ptr1 == *ptr2 && *ptr1 != '\0' && *ptr2 != '\0') {
			ptr1++;
			ptr2++;
		}
		if (strlen(s1) - strlen(s2) == 1)
			ptr1++;
		else if (strlen(s2) - strlen(s1) == 1)
			ptr2++;
		else if (strlen(s1) == strlen(s2) &&
				*ptr1 == *(ptr2 + 1) && *(ptr1 + 1) == *ptr2) {
					ptr1 += 2;
					ptr2 += 2;
				}
		else {
			printf("no\n");
			continue;
		}
		while (*ptr1 == *ptr2 && *ptr1 != '\0' && *ptr2 != '\0') {
			ptr1++;
			ptr2++;
		}
		if (ptr1 - s1 == strlen(s1) && ptr2 - s2 == strlen(s2))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
