//寫一個程式讀入兩個整數 a、b 並計算出 a 加到 b 的和。

#include <stdio.h>
main()
{
  int a, b, ans;
  scanf("%d", &a);
  scanf("%d", &b);

  ans = (a + b) * ((a > b) ? (a - b + 1) : (b - a + 1)) / 2;
  printf("%d\n", ans);
}
