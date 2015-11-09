//寫一個程式讀入三個正整數 a、b、c並判定由 a、b、c 為邊長的
//三角形為銳角、鈍角或是直角三角形，如果為銳角三角形則輸出 1
//，鈍角三角形則輸出 2，直角三角形則輸出 3。題目保證 a、b、c
//可形成一三角形。

#include <stdio.h>
main()
{
  int a, b, c, output;
  int a2, b2, c2;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  a2 = a * a;
  b2 = b * b;
  c2 = c * c;

  if (!((a + b > c) && (a - b < c) && (b - a < c))) //無法形成三角形輸出0
    output = 0;
  else if ((-a2 + b2 + c2 == 0) || (a2 - b2 + c2 == 0) || (a2 + b2 - c2 == 0))
    output = 3;
  else if ((-a2 + b2 + c2 < 0) || (a2 - b2 + c2 < 0) || (a2 + b2 - c2 < 0))
    output = 2;
  else if ((-a2 + b2 + c2 > 0) && (a2 - b2 + c2 > 0) && (a2 + b2 - c2 > 0))
    output = 1;
  else  //其他狀況，以防錯誤
    output = -1;

  printf("%d\n", output);
} 
