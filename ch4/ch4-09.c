//寫一個程式來解決以下問題。有雞、兔子和螃蟹在一個籠子裡。
//現給定這些動物的總數，這些動物的腳數以及這些動物尾巴的總數，請
//計算兔子、雞和螃蟹的數量。如果給定的數子不可能有解，(如 9、48、及
//20)，程式應該輸出 0。

#include <stdio.h>
main()
{
  int number, foot, tail;
  int rabbit, chicken, crab;
  scanf("%d", &number);
  scanf("%d", &foot);
  scanf("%d", &tail);

  crab = number - tail;
  rabbit = (foot - 2 * tail - 8 * crab) / 2;
  chicken = number - crab - rabbit;

  if(8 * crab + 4 * rabbit + 2 * chicken != foot)
    printf("0\n");
  else {
    printf("%d\n", rabbit);
    printf("%d\n", chicken);
    printf("%d\n", crab);
  }
}
