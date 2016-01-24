/*
寫一個程式將地圖中的國家著色。假設一個地圖有 n 個國家，是否
能用 c 種顏色將這些國家著色，使得相鄰的國家都有不同的顏色?
假設每一個國家有 1 到 n 個唯一代號，且每一個顏色也有 1 到 c
個唯一代號。輸入的第一行包括國家數目 n ，顏色數目 c ，以及
相鄰的國家對數 p 。以下 p 行每一行代表兩個鄰的國家的代號。
如果著色問題存在解，則依序輸出 n 個國家所著的顏色代號。由於
對稱關係解不會是唯一，所以請輸出如果將解看成一個字串的話，
字典順序為最小的解。如果不存在解，則輸出"no solution"
參數規範: 0 < n <= 20, 0 < c <=6, 0 < p <= 400
*/

#include <stdio.h>

int check_neighbor(int color_array[], int p, int neighbor[][2])
{
	int i;
	for (i = 0; i < p; i++)
		if (color_array[(neighbor[i][0])] == color_array[(neighbor[i][1])])
			return 0;
	return 1;
}

int draw (int nth, int n, int c, int p, int neighbor[][2], int color_array[])
{
	int i;
	int sol = 0;
	
	if (nth == n) {
		if (check_neighbor(color_array, p, neighbor))
			return 1;
		else
			return 0;
	}
	
	for (i = 1; i <= c && !sol; i++) {
		color_array[nth] = i;
		sol = draw(nth + 1, n, c, p, neighbor, color_array);
	}
	
	return sol;
}

int main (void)
{
	int n, c, p;
	int neighbor[400][2];
	int color_array[20];
	int i;
	
	scanf("%d%d%d", &n, &c, &p);
	
	for (i = 0; i < p; i++)
		scanf("%d%d", &(neighbor[i][0]), &(neighbor[i][1]));
	
	if (draw(0, n, c, p, neighbor, color_array) == 0)
		printf("no solution\n");
	else {
		for (i = 0; i < n; i++)
			printf("%d ", color_array[i]);
		printf("\n");
	}
	
	return 0;
}
