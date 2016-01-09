/*
編寫一個程式來連接字串。給定 m 個長度不超過 n 的字串
，每個字串只包含小寫英文字母，不同字串開始字元不同，
結束字元也不同，一個字串的開始與結束字元也不同。現在
你需要將所有字串「串聯」再一起。兩個字串可以串聯再一
起的條件是前面字串的結尾字元與後面字串的開頭字元必須
相同。例如你可以連接 cat 與 type 得到 catype。現在寫
一個程式來連接所有的字串，輸出是最後的結果字串，本題
保證有唯一解。
參數規範: 0 < n <= 32, 2 < m <= 26
*/

#include <stdio.h>
#include <string.h>

int find_first_head(char head[], char tail[], int m)
{
	int i, j, flag;
	for (i = 0; i < m; i++) {
		flag = 0;
		for (j = 0; j < m; j++) {
			if (head[i] == tail[j])
				flag++;
		}
		if(flag == 0)
			return i;
	}
	return -1;	
}

int find_nth_head(char last_tail, char head[], int m)
{
	int i;
	for (i = 0; i < m; i++)
		if (last_tail == head[i])
			return i;
	return 0;
}

int main (void)
{
	char s[26][33], out[26 * 32 + 1] = "\0";
	char head[26], tail[26], series_head[26] = {0}, next_head;
	int m = 0, len;
	int i, j;
	
	while (scanf("%s", s[m]) != EOF) {
		head[m] = s[m][0];
		len = strlen(s[m]);
		tail[m] = s[m][len - 1];
		m++;
	}
	
	series_head[0] = find_first_head(head, tail, m);
	next_head = tail[series_head[i]];
	
	for (i = 1; i < m; i++) {
		series_head[i] = find_nth_head(next_head, head, m);
		next_head = tail[series_head[i]];
	}
	
	out[0] = s[series_head[0]][0];
	out[1] = '\0';
	for (i = 0; i < m; i++)
		strcat(out, s[series_head[i]] + 1);
	printf("%s\n", out);
	
	return 0;
}
