//作業 3.10 寫一個程式讀入五個整數 a、b、c、d、e。計算圖 3.1
//中物體的表面積，你可以想像該物體是一個長、寬、高為 a、b、c
//的長方體，每一面中央都是凹進去的，而凹進去的深度為 d，沒凹
//進去的邊框寬度為 e 。

#include <stdio.h>
main()
{
  int a, b, c, d, e, surface_area;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &e);

  surface_area = (2 * (a*b + b*c + a*c)) + 
                 8 * d * ((a - 2*e) + (b - 2*e) + (c - 2*e));
  printf("%d\n", surface_area);
}
