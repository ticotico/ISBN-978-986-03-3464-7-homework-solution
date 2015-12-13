//請寫一個程式計算 cos(x)， 其中 x 是一個輸入的雙倍準數，
//0.0 <= x <= 2PI
//cos(x) = sigma(n = 0...inf, (-1)^n / (2n)! * x^(2n)

#include <stdio.h>
main()
{
	double powerx = 1.0;
	double x, cosx = 0.0, cn = 1.0;
	int i;
	scanf("%lf", &x);
	for(i = 0; i <=15; i++) {
		cosx += powerx / cn;
		powerx *= x * x;
		cn *= -1 * ((2 * i + 1) * (2 * i + 2)) ;
	}
	printf("%f\n", cosx);
}
