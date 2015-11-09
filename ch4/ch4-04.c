//寫一個程式讀入四個整數 a、b、c、d，本題保證 (a,b) 及
// (c,d) 不會水平或垂直共線。請計算以 (a,b) 及 (c,d) 為
//兩對角頂點的長方形周長。

#include <stdio.h>
main()
{
  int a, b, c, d, length = 0;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  if ((a == c) || (b == d))
    length = 0;
  else {
    length += (a > c) ? (2 * (a - c)) : (2 * (c - a));
    length += (b > d) ? (2 * (b - d)) : (2 * (d - b));
  }
  printf("%d\n", length);
}
