//寫一個程式讀取一個正整數 n，然後由 n 以反向順序列印直到 1。

#include <stdio.h>
main()
{
  int n, i;
  scanf("%d", &n);
  for (i = n; i > 0; i--)
    printf("%d\n", i);
}
