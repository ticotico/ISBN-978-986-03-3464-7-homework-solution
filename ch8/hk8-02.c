//寫一個函式 polynomial 計算多項式值。
//函式原型 double polynomial (double x, double coef[], int n);
//polynomial 的第一個參數是 x。
//polynomial 的第二個參數 coef 是一個表示係數的陣列，
//x^k 的係數就是 coef[k]。
//第三個參數是多項式的次數。
//輸入第一行為n，多項式的次數。
//以下 n + 1 行為多項式係數。
//下一行為 x 的個數 m ，以下 m 行為 x。
//輸出有 m 行，每一行為ㄧ個 x 的多項式值。
//參數規範: 0 < n <= 64, 0 < m <= 64

#include <stdio.h>
double polynomial (double x, double coef[], int n)
{
	double result = 0.0;
	double xpower = 1.0;
	int i;
	for (i = 0; i <= n; i++) {
		result += coef[i] * xpower;
		xpower *= x;
	}
	return result;
}
#define N 33

int main(void)
{
	double coefficient[N];
	double x, y;
	int i, n, m;
	
	scanf("%d", &n);
	for (i = 0; i <= n; i++)
		scanf("%lf", &(coefficient[i]));
	
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%lf", &x);
		y = polynomial (x, coefficient, n);
		printf("%f\n", y);
	}
	
	return 0;
}
