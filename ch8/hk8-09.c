//編寫一個函式 posneg 計算一個 4 乘 4 的整數陣列中
//正數及負數的數目。函式 posneg 的原形如下。負數的
//數量放在 result[0]，正數的數量放在 result[1]
//void posneg(int array[4][4], int result[2])

#include <stdio.h>

void posneg(int array[4][4], int results[2])
{
	int i, j;
	int pos = 0, neg = 0;
	
	for (i =0; i < 4; i++)
		for (j = 0; j < 4; j++) {
			if(array[i][j] > 0)
				pos++;
			else if (array[i][j] < 0)
				neg++;
		}
	
	results[0] = neg;
	results[1] = pos;
			
}

int main (void)
{
	int i, j, array[4][4], results[2];
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &(array[i][j]));
	
	posneg(array, results);
	printf("%d\n", results[0]);
	printf("%d\n", results[1]);
	
	return 0;
}
