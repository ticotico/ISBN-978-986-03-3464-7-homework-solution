//寫一個程式讀入兩個整數 n、i >= 0 並計算 n^i。
//注意當 i 等於 0 時必須輸出 1 。

#include <stdio.h>
main()
{
  int i, n, k, output = 1;
  scanf("%d", &n);
  scanf("%d", &i);

  for (k = 1; k <= i; k++) 
    output *= n;

  if (i >= 0)
    printf("%d\n", output);
}
