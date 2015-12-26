/*
編寫一個函式 add_n 將一個整數加值。
int add_n (int *iptr, int n);
函式 add_n 第一個參數維一個指標 iptr 指向要加值的整數，
第二個參數是要加的值 n。add_n 首先檢查 iptr 是否為NULL
，如果是則立即回傳 0。如果 iptr 不是 NULL，add_n會將
iptr 所指到的整數的值增加 n， 並回傳 iptr 所指到變數的
新值。注意因為用使用 NULL 所以程式必須引入<stdio.h>。
*/

#include <stdio.h>
int add_n (int *iptr, int n)
{
	if (iptr == NULL)
		return 0;
	else
		return *iptr + n;
}

int main(void)
{
	int i, j, k;
	scanf("%d%d", &i, &j);
	printf("i = %d\n", i);
	k = add_n(NULL, j);
	printf("i = %d, k = %d\n", i, k);
	k = add_n(&i, j);
	printf("i = %d, k = %d\n", i, k);
	
	return 0;
}
