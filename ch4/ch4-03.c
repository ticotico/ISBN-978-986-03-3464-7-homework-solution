//寫一個程式讀入四個整數 a、b、c、d。計算以 (a,b) 及
// (c,d) 為兩對角頂點的長方形面積。注意 (a,b) 及 (c,d)
//若是水平或垂直共線則面積為 0 。

#include <stdio.h>
main()
{
  int a, b, c, d, area;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  area = (c - a) * (b - d);
  area = (area > 0) ? area : -area;
  printf("%d\n", area);
}
