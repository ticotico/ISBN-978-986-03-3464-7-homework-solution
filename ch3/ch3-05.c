//寫一個程式找零錢。程市首先讀入一介於 1 與 100 之間的整數，
//然後用最少數目的 50、 10、 5、 1 硬幣湊足給定的整數。

#include <stdio.h>
main()
{
  int a, b, c, d, i;
  scanf("%d", &i);
  a = i / 50;
  i %= 50;
  b = i / 10;
  i %= 10;
  c = i / 5;
  i %= 5;
  d = i / 1;
  i %= 1;
  
  printf("%d\n", a);
  printf("%d\n", b);
  printf("%d\n", c);
  printf("%d\n", d);
}
