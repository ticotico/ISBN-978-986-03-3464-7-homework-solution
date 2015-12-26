/*
編寫一個函式  max 回傳一個指標陣列中各指標所指到的最大
整數。一個指標陣列就是一個陣列，陣列中元素均為指標。例
如範例 9.20 中，iptr 就是一個包括十個整數指標的指標陣列
*iptr[]，所以每個元素均為ㄧ個指向整數的指標，max 的第二
個參數 n 為 iptr 中有幾個指標
*/

#include <stdio.h>

int max(int *iptr[], int n)
{
	int result = *iptr[0];
	int i;
	for (i = 1; i < n; i++)
		result = (result > *(iptr[i])) ? result : *(iptr[i]);
	return result;
}

int main (void)
{
	int i;
	int array[10];
	int *iptr[10];
	
	for (i = 0; i < 10; i++) {
		scanf("%d", &(array[i]));
		iptr[i] = &(array[i]);
	}
	
	printf("%d\n", max(iptr, 10));
	return 0;
}
