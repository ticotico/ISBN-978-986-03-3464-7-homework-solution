//寫一個程式讀入三個正整數 a、b、c。如果邊長為
// a、b、c 的三角形不存在則輸出零，否則輸出1。

#include <stdio.h>
main()
{
  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if ((a + b > c) && (a - b < c) && (b - a < c))
    printf("%d\n", 1);
  else
    printf("%d\n", 0);
}
