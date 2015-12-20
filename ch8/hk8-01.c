//8.1 寫一個程式計算兩點距離，兩點以極座標表示為
//(r1, theta1) 及 (r2, theta2)。
//輸入一行為r1, theta1, r2, theta2。
//輸出為兩點之間的距離，注意我們要使用 sin 及 cos
//函數，所以要引入 math.h 。

#include <stdio.h>
#include <math.h>
int main(void)
{
	double r[2], theta[2];
	double x[2], y[2];
	double d;
	scanf("%lf%lf", &(r[0]), &(theta[0]));
	scanf("%lf%lf", &(r[1]), &(theta[1]));
	x[0] = r[0] * cos(theta[0]);
	y[0] = r[0] * sin(theta[0]);
	x[1] = r[1] * cos(theta[1]);
	y[1] = r[1] * sin(theta[1]);
	d = (x[1] - x[0]) * (x[1] - x[0]) +
		(y[1] - y[0]) * (y[1] - y[0]);
	d = sqrt(d);
	printf("%f\n", d);
	return 0;
}
