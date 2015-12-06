//寫一個程式分奇數偶數，輸入的第一行為數列長度 n。輸入的第二行
//為 n 個整數，然後輸出兩行，第一行是數列中的奇數，第二行是數列
//中的偶數。數字之間用空格隔開。
//參數規範 0 < n <= 100。

#include <stdio.h>
main()
{
  int a[101], n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < n; i++)
    if(a[i] % 2 == 1 || a[i] % 2 == -1)
      printf("%d ", a[i]);
  printf("\n");

  for (i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      printf("%d ", a[i]);
  printf("\n");
}
