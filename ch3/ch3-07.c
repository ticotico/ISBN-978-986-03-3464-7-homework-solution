//作業3-7 寫一個程式毒入四個整數 a、b、c、d 並且保證
// c > a 且 d > b。計算以 (a,b)為左下角，(c,d)為右上
//角的長方形面積及周長。

#include <stdio.h>
main()
{
  int a, b, c, d;
  int area, side_length;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  area = (c - a) * ( d - b);
  side_length = 2 * ((c - a) + (d - b));

  printf("%d\n", area);
  printf("%d\n", side_length);
}
