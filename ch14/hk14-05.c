/*
寫程式計算最長共同子序列(longest common subsequence)，一個
序列的子序列是由去除元序列中的一些字元而得。例如 aed 是 bacedf
的一個子序列。而兩個序列的最長共同子序列即為兩個序列的共同
子序列中長度最長的。因此 ade 即為 abcde 和 zzadfess的最長
共同子序列之一。
輸入有兩行。每一行為一個長度不超過 n 的小寫字母字串。
輸出為最長共同子序列長度。
參數規範: 0 < n <= 16
*/

#include <stdio.h>

int co_max_len(const char *str1, const char *str2)
{
	if (*str1 == '\0' || *str2 == '\0')
		return 0;
	if (*str1 == *str2)
		return co_max_len(str1 + 1, str2 + 1) + 1;
	
	int len1 = co_max_len(str1 + 1, str2);
	int len2 = co_max_len(str1, str2 + 1);
	return (len1 > len2) ? len1 : len2;
}

int main (void)
{
	char s1[17], s2[17];
	scanf("%s%s", s1, s2);
	printf("%d\n", co_max_len(s1, s2));
	return 0;
}
