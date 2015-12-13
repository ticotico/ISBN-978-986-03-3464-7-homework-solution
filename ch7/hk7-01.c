//請寫一個程式計算 sin(x)， 其中 x 是一個輸入的雙倍準數，
//0.0 <= x <= 2PI
//sin(x) = sigma(n = 0...inf, (-1)^n / (2n + 1)! * x^(2n + 1)

#include <stdio.h>
main()
{
  double x, sinx = 0.0, cn = 1.0, xpower = 1;
  int n;
  scanf("%lf", &x);

  xpower *= x;

  for(n = 1; n <= 15; n++) {
    sinx += xpower / cn;
    cn *= 2 * n * (2 * n + 1);
    xpower *= x * x * (-1.0);
  }
  printf("%f\n", sinx);
}
