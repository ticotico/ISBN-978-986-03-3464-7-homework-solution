/*
編寫一個排版程式，程式必須將輸入的字逐一輸入，再逐一
輸出。一個字的定義是連續非空白字元。例如 7、empire都
算是字。也就是說我們可以用 scanf("%s", string) 讀入一
個字。
輸入的第一行是每行可輸出的字元數 m ，之後就是要排版的
文章。一個英文字的最大長度為 n 個字元。輸出是將所有的
字依序印出。字與字中間要空一個，且一行不可輸出超過 m 
個字元 (包含空白，但不包含換行)
參數規範: 0 < n <= 32, n <= m <= 256
*/

#include <stdio.h>
#include <string.h>
int main(void)
{
	char buf_in[34], buf_out[256  * 100 + 1] = "\0", space[2] = " \0";
	int m;
	scanf("%d", &m);
	while (scanf("%s", buf_in) != EOF) {
		if (strlen(buf_in) + strlen(buf_out) + 1 <= m) {
			strcat(buf_out, buf_in);
			strncat(buf_out, space, 2);
		}
		else {
			printf("%s\n", buf_out);
			strcpy(buf_out, buf_in);
			strncat(buf_out, space, 2);
		}
	}
	printf("%s\n", buf_out);
	return 0;
}
