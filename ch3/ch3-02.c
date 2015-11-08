//寫一個程式毒入一個整數，如果該整數是偶數則輸出1，否則輸出0。

#include <stdio.h>
main()
{
  int i, k;
  scanf("%d", &i);
  k = (i % 2 == 0);
  printf("%d\n", k);
}
