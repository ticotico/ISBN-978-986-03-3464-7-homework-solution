//寫一個程式計算自 1970 年 1 月 1 日到某一特定日期的天數，
//如果日期有誤或是在 1970年 1 月 1 日之前則輸出 0。

#include <stdio.h>
main() 
{
  int year, month, day;
  int sum_day = 0;
  int i;
  scanf("%d", &year);
  scanf("%d", &month);
  scanf("%d", &day);

  if (year < 1970 || year >= 3000 || month <= 0 || month > 12) sum_day = 0;
  else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) sum_day = 0;
  else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) sum_day = 0;
  else if (month == 2 && day > (28 + ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))) sum_day = 0;
  else {
    for (i = 1970; i < year; i++) {
      if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
        sum_day += 366;
      else
        sum_day += 365;
    }

    switch (month) {
    case 12:
      sum_day += 30;
    case 11:
      sum_day += 31;
    case 10:
      sum_day += 30;
    case 9:
      sum_day += 31;
    case 8:
      sum_day += 31;
    case 7:
      sum_day += 30;
    case 6:
      sum_day += 31;
    case 5:
      sum_day += 30;
    case 4:
      sum_day += 31;
    case 3:
      sum_day += 28 + ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
    case 2:
      sum_day += 31;
    }

    sum_day += day;
  }

  printf("%d\n", sum_day);
}
