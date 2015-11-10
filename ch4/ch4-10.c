//寫一個程序決定三個線段是否能形成一個三角形。請注意我們
//可以平移線段，但不能旋轉或是翻轉線，題目假設所有線段有
//不同的斜率，所以你不必擔心有面積為 0 的三角形。
//輸入有 12 行，每 4 行代表一個線段的起點和終點的 x 及 y
//座標。如果三個平面線段可形成一個三角形則輸出 1，否則輸出
//0。

#include <stdio.h>
main()
{
  int x1, y1, x2, y2;
  int x3, y3, x4, y4;
  int x5, y5, x6, y6;
  int output = 0;
  scanf("%d", &x1);
  scanf("%d", &y1);
  scanf("%d", &x2);
  scanf("%d", &y2);
  scanf("%d", &x3);
  scanf("%d", &y3);
  scanf("%d", &x4);
  scanf("%d", &y4);
  scanf("%d", &x5);
  scanf("%d", &y5);
  scanf("%d", &x6);
  scanf("%d", &y6);

  int vx1 = x2 - x1, vx2 = x4 - x3, vx3 = x6 - x5;
  int vy1 = y2 - y1, vy2 = y4 - y3, vy3 = y6 - y5;

  if ((vx1 == vx2 + vx3) && (vy1 == vy2 + vy3))
    output = 1;
  else if ((vx1 == vx2 - vx3) && (vy1 == vy2 - vy3))
    output = 1;
  else if ((vx1 == -vx2 + vx3) && (vy1 == -vy2 + vy3))
    output = 1;
  else if ((vx1 == -vx2 - vx3) && (vy1 == -vy2 - vy3))
    output = 1;

  printf("%d\n", output);
}
