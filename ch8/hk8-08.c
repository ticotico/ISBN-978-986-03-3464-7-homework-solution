//實作函式 max 在一個 4 乘 4 的整數陣列中尋找
//尋找最大值。函式 max 的原型如下
//int max(int array[100][100])

#include <stdio.h>

int max(int array[4][4])
{
	int result = array[0][0];
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (array[i][j] > result)
				result = array[i][j];
			
	return result;
}

int main(void)
{
	int i;
	int j;
	int array[4][4];
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", &(array[i][j]));
	
	printf("%d\n", max(array));
	return 0;
}
