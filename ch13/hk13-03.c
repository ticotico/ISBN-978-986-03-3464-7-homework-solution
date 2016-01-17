/*
寫一個程式列印一個點矩陣。我們假設這個點矩陣深度只有一個位元。例如
以下即為一個 3 乘 12 的點矩陣。
	101010111010
	010110110001
	111111100111
	
我們將用 n 個無號整數儲存點矩陣。由於一個 3 乘 12 的點矩陣只需要 36
個位元，所以我們可以用兩個 32 位元的無號整數代表。第一個整數數組是
2879762492，而第二個整數是1879048192。也就是說這個點矩陣的點數不一定
是 32 的整數，所以第二個整數後面 32 * 2 - 36 = 28個位元事實上都無關緊要
，所以我們補 0 。
輸入有三行，第一行是矩陣寬度 u 與高度 h。第二行是當點矩陣為 1 或 0 要輸出
的非空白字元。第三航為代表點矩陣內容的無號整數。題目保證給定剛好數目的無號
整數。輸出是點矩陣，分別用第二行給定的字元依序列印。
參數規範: 0 < m <= 256, 0 < h <= 256, n = [wh/32]
*/

#include <stdio.h>

int main (void)
{
	unsigned int point_array[256 * 256 / 32];
	int w, h;
	int i;
	int points;
	int mask, temp;
	char A, B;
	scanf("%d%d", &w, &h);
	scanf("%c%c", &A, &B);
	
	//decide points by [w * h / 32]
	points = (w * h / 32) + ((w * h % 32 == 0) ? 0 : 1);
	
	//input numbers to # point_array
	for (i = 0; i < points; i++)
		scanf("%d", &(point_array[i]));
	
	//print array
	for(i = 0; i < w * h; i++) {
		mask = 1 << (31 - i % 32);
		temp = mask & point_array[i / 32];
		printf("%c", (temp == 0) ? B : A);
		if (i % w == w - 1)
			printf("\n");
	}
	
	return 0;
}
