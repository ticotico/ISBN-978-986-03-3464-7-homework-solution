//寫一個程式計算一元二次方程式的根，首先讀取三個倍準數，
//a, b, c。然後計算方程式 ax^2 + bx + c = 0兩個根。
//假設 b^2 - 4ac > 0 ，所以必存在兩個實根。
//輸出為兩個根，第一個小的，第二個大的。

#include <stdio.h>
#include <math.h>

void swap(double *a, double *b)
{
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int main(void)
{
	double a, b, c, r1, r2;
	scanf("%lf%lf%lf", &a, &b, &c);
	r1 = (-b - sqrt(b*b - 4*a*c)) / (2 * a);
	r2 = (-b + sqrt(b*b - 4*a*c)) / (2 * a);
	if(r1 > r2) swap(&r1, &r2);
	printf("%f\n%f\n", r1, r2);
	return 0;
}
