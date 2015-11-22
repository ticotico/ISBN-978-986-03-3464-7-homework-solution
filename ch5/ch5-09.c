//寫一個程式分解質因數。輸入一正整數 n。輸出為 n 的質因數
//及其次方。輸出實質因數由小至大，先輸出質因數在輸出次方。
//例如輸入 123456，輸出為 2 6 3 1 643 1

#include <stdio.h>
main()
{
  int input, power_count = 0, i;
  scanf("%d", &input);

  for (i = 2; i * i <= input; i++) {
    if (input % i == 0) {
      while (input % i == 0) {
        input /= i;
        power_count++;
      }
      printf("%d %d ", i, power_count);
      power_count = 0;
    }
  }

  if (input != 1) printf("%d 1 ",input);

  printf("\n");
}
