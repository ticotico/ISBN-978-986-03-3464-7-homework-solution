//寫一個程式將一個給定的數字做轉換。
//轉換的方法是將數字的最後一位變成第一位數，
//例如1234會變成4123。但是當0是最後一位時，
//0會被轉換成第一位然後被丟棄，例如1230轉換成123
//輸入為兩個數字，第一個為被轉換的數字，
//第二個為轉換的次數。

#include <stdio.h>
main()
{
  int number, convert_time;
  int i, j, power, a, b;
  scanf("%d%d", &number, &convert_time);
  for (i = 1; i <= convert_time; i++) {
    for (power = 1; number / (power * 10) > 0; power *= 10);
    a = number / power;
    b = number % power;
    number = 10 * b + a;
  }
  printf("%d\n", number);
}
