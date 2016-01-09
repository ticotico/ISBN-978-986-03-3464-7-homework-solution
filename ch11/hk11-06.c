/*
編寫一個程式玩 hangman 遊戲。 hangman 的玩法
是有一個未知字串，如果該字母有在未知字串出現
，則該字母在未知字串中會被顯示出來。玩家此時
可以猜下一個字母，直到猜出答案。本題假設所有
英文字母皆為小寫。
*/

#include <stdio.h>
#include <string.h>

int main (void)
{
	char s1[80], s2[80], s3[80], temp_s1[80], delimeter[2];
	char *start = temp_s1;
	int i, j, len1, len2;
	scanf("%s", s1);
	scanf("%s", s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	
	for (i = 0; i < len1; i++)
		s3[i] = '*';
	s3[i] = '\0';
	
	for (i = 0; i < len2 && strcmp(s1, s3) != 0; i++) {
		strcpy(temp_s1, s1);
		for (j = 0; j < len1; j++) 
			if(temp_s1[j] == s2[i])
				s3[j] = s2[i];
		
		printf("%s\n", s3);
	}
	
	return 0;
}
