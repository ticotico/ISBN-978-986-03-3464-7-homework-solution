//寫一個程式讀入三個平面上的座標，
//然後印出其中距離原點最遠的點，
//如果兩個或多個點，有相同的距離，
//輸出最先出現的點座標。

#include <stdio.h>
main()
{
  int a, b;

  scanf("%d", &a);
  scanf("%d", &b);
  int x = a, y = b;

  scanf("%d", &a);
  scanf("%d", &b);
  if ((a*a + b*b) > (x*x + y*y)) {
    x = a;
    y = b;
  }

  scanf("%d", &a);
  scanf("%d", &b);
  if ((a*a + b*b) > (x*x + y*y)) {
    x = a;
    y = b;
  }
  printf("%d\n", x);
  printf("%d\n", y);
}
