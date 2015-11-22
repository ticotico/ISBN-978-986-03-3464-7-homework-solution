//寫一個程式讀入一正整數 n 。首先印出 1 到 n，在印出
//n - 1 到 1 。

#include <stdio.h>
main()
{
  int i, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    printf("%d\n", i);
  for (i = n; i >= 1; i--)
    printf("%d\n", i);
}
