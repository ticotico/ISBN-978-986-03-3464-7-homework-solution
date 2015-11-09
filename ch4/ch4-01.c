//寫一個程式讀入三個個正整數 a、b、c，計算
//計算並印出其中的最小值。

#include <stdio.h>
main()
{
  int a, b, c, min;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  min = (a < b) ? a : b;
  min = (c < min) ? c : min;
  printf("%d\n", min);
}
