/*
寫一個程式解線性系統 Ax = y。其中 A 是 n 乘 n 矩陣，
x 及 y 都是 n 乘 1 的向量。當給定 A 及 y 時求解 x。
為求簡單起見，我們假設 A 是一個上三角矩陣。
void upper_solver(double *A, double *x, double *y, int n);
函示 upper_solver 的第一個參數是指向 A 的指標。注意為了
節省記憶體我們只存 A 的上三角部分，而且存成一維陣列。
upper_solver的第二個參數是指向 x 的指標。 必須將 x 的
解放在這裡。upper_solver 的第三個參數是指向 y 的指標。
upper_solver 的第四個參數是矩陣大小 。
*/

#include <stdio.h>
#define N 256

void upper_solver(double *A, double *x, double *y, int n)
{
	double *ptr = A + (n * (n + 1)) / 2 -1;
	int i, j;
	double sum;
	
	for (i = 1; i <= n; i++) {
		sum = 0.0;
		for (j = n - 1; j > n - i; j--) {
			sum += *ptr * x[j];
			ptr--;
		}
		x[n-i] = (y[n-i] - sum) / *ptr;
		ptr--;
	}
}

int main(void)
{
	int i, j;
	int n;
	double A[N * (N + 1) / 2];
	double *aptr = A;
	double x[N];
	double y[N];
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++) {
			scanf("%lf", aptr);
			aptr++;
		}
		
	for (i = 0; i < n; i++)
		scanf("%lf", &y[i]);
	
	upper_solver(A, x, y, n);
	
	for (i = 0; i < n; i++)
		printf("%f\n", x[i]);
	
	return 0;
}
