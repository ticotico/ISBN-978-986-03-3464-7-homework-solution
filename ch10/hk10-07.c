/*
編寫一個程式旋轉圖形，一個圖形是n列m行的數字或英文字母
，程式必須將圖型旋轉三次，並印出每次旋轉之後的結果。
輸入有 n 行，每行有 m 個連續數字或英文字母。程式必須處
理所有的字元直到 EOF。輸出有四組，首先是原來得圖形，之
後三組為圖形順時鐘旋轉三次每次旋轉之後的結果。
*/
#include <stdio.h>
int main (void)
{
	int c[128][128], in_c;
	int i, j, k;
	int n = 0, m = 0;
	while (scanf("%c", &in_c) != EOF) {
		k = m;
		if (in_c == '\n') {
			n++;
			m = 0;
		}
		else {
			c[n][m] = in_c;
			m++;
		}
	}
	m = k;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			printf("%c", c[i][j]);
		printf("\n");
	}
	
	for (i = 0; i < m; i++) {
		for (j = n - 1; j >= 0; j--)
			printf("%c", c[j][i]);
		printf("\n");
	}
	
	for (i = n - 1; i >= 0; i--) {
		for (j = m - 1; j >= 0; j--)
			printf("%c", c[i][j]);
		printf("\n");
	}
	
	for (i = m - 1; i >= 0; i--) {
		for (j = 0; j < n; j++)
			printf("%c", c[j][i]);
		printf("\n");
	}
	
	return 0;
}
