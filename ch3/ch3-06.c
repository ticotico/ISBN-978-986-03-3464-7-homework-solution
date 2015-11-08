//寫一個程式讀入四個正整數 a、b、c、d、並保證點 (a,b) 及 (c,d)
//為不同點，如果連接點 (a,b) 及 (c,d) 的值線通過原點則輸出 1，
//其他狀況則輸出 0。

#include <stdio.h>
main()
{
  int a, b, c, d, output;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  output = (b * c == a * d);
  printf("%d\n", output);
}
