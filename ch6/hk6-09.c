//寫一個程式玩井字遊戲。我們用 1 到 9 的數字代表井字遊戲由上
//到下，由左到右的九個格子，1 代表左上角， 9 代表右下角。
//輸入為一行雙方下子的紀錄，最多有9個數字。如果任一方獲勝，
//則輸出或生一方下子的最後一個數字，。如果平手則輸出為 0 。

#include <stdio.h>
main()
{
  int i, j, a[4][4] = {0};
  int input, count = 0, flag_win = 0, n;
  int row, column;

  for(n = 1; n <= 9 && flag_win != 1; n++) {
    scanf("%d", &input);
    row = (input - 1) / 3;
    column = (input - 1) % 3;
    a[row][column] = (n % 2 == 1) ? 1 : 2;

    count = 0;
    for(i = 0; i < 3; i++)
      if(a[row][i] == a[row][column]) count ++;
    if(count == 3) flag_win = 1;

    count = 0;
    for(i = 0; i < 3; i++)
      if(a[i][column] == a[row][column]) count++;
    if(count == 3) flag_win = 1;

    if(input == 1 || input == 5 || input == 9) {
      count = 0;
      for(i = 0; i < 3; i++)
        if(a[i][i] == a[0][0]) count ++;
      if(count == 3) flag_win = 1;
    }

    if(input == 3 || input == 5 || input == 7) {
      count = 0;
      for(i = 0; i < 3; i++)
        if(a[2 - i][i] == a[0][2]) count ++;
      if(count == 3) flag_win = 1;
    }
  }

  printf("%d\n", (flag_win == 1) ? input : 0);
}
