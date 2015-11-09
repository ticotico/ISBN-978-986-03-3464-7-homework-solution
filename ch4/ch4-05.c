//作業4.5 寫一個程式讀入三個非零整數 a、b、c。如果
// f(x) = ax^2 + bx +c = 0 有重根則輸出零，有兩相異
//實根則輸出 1，有兩相異虛根則輸出 -1。

#include <stdio.h>
main()
{
  int a, b, c, output;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if(b * b - 4 * a * c == 0)
    output = 0;
  else if (b * b - 4 * a * c > 0)
    output = 1;
  else if (b * b - 4 * a * c < 0)
    output = -1;
  else
    output = -999;
  if(a * b * c == 0)
    output = -666;
  printf("%d\n", output);
} 
