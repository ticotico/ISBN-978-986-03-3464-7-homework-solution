//寫一個程式在二進制、八進制、十進制之間做數字轉換。
//輸入第一個數字是輸入格式: 2代表二進制， 10 代表十進制
//8代表八進制。
//輸入第二個數字 n 代表數字有幾位數。以下的 n個數字為輸
//入數字由左到右的數字。
//最後一個數字是輸出的格式，格式同第一個數字。

#include <stdio.h>
int main()
{
  int n, base, input;
  int power = 1, sum = 0, temp, i;
  scanf("%d", &base);
  scanf("%d", &n);

  if ((n < 10) && (base >= 2) && (base <= 10))
    for (i = 1; i < n; i++) power *= base;
  else
    return 0;

  //將輸入的數字加起來
  for (i = n; i >= 1; i--) {
    scanf("%d", &input);
    if (input < 0 || input >= base) {
      printf("Error: illegal input %d\n", input);
      sum = 0;
      return 0;
    } else {
        sum += input * power;
        power /= base;
    }
  }

  scanf("%d", &base);
  if((base < 2) && (base > 10))
    return 0;

  //判斷要轉換的數字有幾位數
  power = 1;
  temp = sum;
  while (temp >= base) {
    temp /= base;
    power *= base;
  }

  //將數字轉換為新的進制
  do {
    printf("%d\n", sum / power);
    sum %= power;
    power /= base;
  } while (sum > 0);

  return 0;
}
