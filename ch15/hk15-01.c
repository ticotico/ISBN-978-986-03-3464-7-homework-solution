/*
給定一個結構 Color。有 r、g、b 三個整數欄位。

各個 Color 相關的函式功能描述如下:
initColor 函式將 c 所指到的 Color 初始化成第二個、第三個、
第四個參數的 r、g、b 值。
averageColor 函式計算一個 Color 陣列中所有r、g、b的個別平
均值。陣列中的元素共有 n 個。最後傳回 r、g、b 平均值所構成
的 Color。
brightness 函式計算 c 所指到的 Color 亮度。計算公式是
b = (r + g + b) / 3。
printColor 將 c 所指到的 Color中的 r、g、b 值以(r、g、b)
的形式印出，最後在印出該 Color 的亮度。
實作以上函式。
*/

#include <stdio.h>
#define N 128

typedef struct{
	int r;
	int g;
	int b;
}Color;

void initColor (Color *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
	return;
}

Color averageColor(Color c[], int n)
{
	Color result;
	int i;
	initColor(&result, 0, 0, 0);
	
	if (n == 0)
		return result;
	
	for (i = 0; i < n; i++) {
		result.r += c[i].r;
		result.g += c[i].g;
		result.b += c[i].b;
	}
	
	result.r /= n;
	result.g /= n;
	result.b /= n;
	
	return result;
}

double brightness(Color *c)
{
	return (double) (c->r + c->g + c->b) / 3.0;
}

void printColor(Color *c)
{
	printf("(%d, %d, %d) %f\n",
		c->r, c->g, c->b, brightness(c));
	return;
}

int main (void)
{
	int n;
	int i;
	int r, g, b;
	Color c[N], average;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &r, &g, &b);
		initColor(&(c[i]), r, g, b);
		printColor(&(c[i]));
	}
	average = averageColor(c, n);
	printColor(&average);
	return 0;
}
