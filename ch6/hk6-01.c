//寫一個程式將一個數列反向列印出。
//輸入的第一行為數列的長度 n，
//第二行為數列中的數字。
//參數規範: 0 < n <= 100

#include <stdio.h>
main()
{
  int a[101], n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = n - 1; i >= 0; i--)
    printf("%d ", a[i]);
}
