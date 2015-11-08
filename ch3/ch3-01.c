//作業3.1 寫一個程式毒入三個整數，計算並輸出他們的連乘積。

#include <stdio.h>

main()
{
  int i, j, k;
  scanf("%d", &i);
  scanf("%d", &j);
  scanf("%d", &k);
  k = i * j * k;
  printf("%d\n", k);
}
