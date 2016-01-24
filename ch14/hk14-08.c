/*
給定一寬度為 w，高度為 h 的矩形板，請將這塊矩形板切割出售，
我們可以在水平或垂直方向將矩形板切成兩塊，切下來的矩形板可以
重複切割。矩形板只能以三種尺寸出售:寬度和高度分別為w1、h1，
或是w2、h2，或是w3、h3，而且因為矩形板有紋路所以不能旋轉。
一塊寬度為 w，高度為 h 矩形板售價為 w * h 元。請寫一個程式
計算我們最多可以賣多少錢。
*/

#include <stdio.h>
#define N_piece 3

int min_piece (int w, int h, int wh[N_piece][2])
{
	int i;
	int cut[N_piece] = {0}, cancut = 0;
	int min = w * h;
	int wh1, wh2;
	
	if (w <= 0 || h <= 0)
		return 0;
	
	for (i = 0; i < N_piece; i++)
		if (w == wh[i][0] && h == wh[i][1])
			return 0;
		
	for (i = 0; i < N_piece; i++)
		if (w >= wh[i][0] && h >= wh[i][1])
			cut[i] = 1;
	for (i = 0; i < N_piece;i++)
		cancut += cut[i];
	if(!cancut)
		return w * h;
	
	
	for (i = 0; i < N_piece; i++)
		if (cut[i]) {
			wh1 = min_piece(w, h - wh[i][1], wh) + min_piece(w - wh[i][0], wh[i][1], wh);
			wh2 = min_piece(w - wh[i][0], h, wh) + min_piece(wh[i][0], h - wh[i][1], wh);
		
			min = (min < wh1) ? min : wh1;
			min = (min < wh2) ? min : wh2;
		}
	
	return min;
}

int main (void)
{
	int i;
	int w, h;
	int wh[N_piece][2];
	
	scanf("%d%d", &w, &h);
	for (i = 0; i < N_piece; i++)
		scanf("%d%d", &(wh[i][0]), &(wh[i][1]));
	printf("%d\n", w * h - min_piece(w, h, wh));
	return 0;
}
