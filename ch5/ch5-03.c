//寫一個程式讀入一正整數 n 並印出 n 組輸出，
//第 i 組是從 1 到 i 的數字。


#include <stdio.h>
main()
{
  int i, j, n;
  scanf("%d", & n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= i; j++)
      printf("%d\n", j);
}
