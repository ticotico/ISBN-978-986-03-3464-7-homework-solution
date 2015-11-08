//作業 3.8 寫一個程式讀入三個整數 a、b、c，其中 a 不等於 0 。
//如果方程式 f(x) = ax^2 + bx + c = 0有重跟則輸出 1，其他狀況
//均輸出 0。

#include <stdio.h>
main()
{
  int a, b, c, output;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  output = ((b * b - 4 * a * c) == 0);
  printf("%d\n", output);
}
