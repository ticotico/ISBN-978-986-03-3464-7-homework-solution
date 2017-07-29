/*
寫一個程式計算兩個四位數的相似度，每個四
位數字其中的數字均不相同且第一位數不為 0
。如果兩個四位數有兩個相同的數字在相同的
位置，那麼就算做一個 A。如果兩個四位數有相
同的數字在不同的位置，那麼算做一個 B。輸入
有兩行。分別為兩個四位數，輸出只有一行，形式
為 aAbB，而 a 及 b 為算出來 A 及 B 的個數。
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char s1[5], s2[5];
	int i, j, count_a = 0, count_b = 0;
	scanf("%s", s1);
	scanf("%s", s2);
	
	for (i = 0; i < 4; i++)
		if (s1[i] == s2[i])
			count_a++;
		
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (s1[i] == s2[j])
				count_b++;
	printf("%dA%dB\n", count_a, count_b - count_a);
	return 0;
}
