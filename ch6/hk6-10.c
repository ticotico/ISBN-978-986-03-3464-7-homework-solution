//寫一個程式模擬鏡子反射，給定一個房間，其寬度為 w，長度為 d。
//你可以想向房間是由 wd 個格子組成。房間裡有許多鏡子，而一個鏡
//子就放在一個房間格子中，以 45 度角放置，鏡子是雙面，兩面都可
//以反射光線，房間周圍有 2(w + d) 個窗口。窗口編號由 0 到 2(w + d) - 1
//。每一個窗口都可以向房間內部檢視。如果我們站在窗口 0 檢視，我
//們將看到窗口 8 。

//輸入的第一行為房間的寬度 w 和長度 d 。以下 d 行每一行有 w 個
//0 或 1，代表該位置是否有鏡子。輸出有 2(w + d) 行，每一行站在
//該窗口向房間內檢視時所會看到的窗口編號。

//參數規範: 0 < w <= 20, 0 < d <= 20
//輸入
//1	5 4
//2	0 1 0 1 0
//3	0 0 1 0 0
//4	1 0 0 1 1
//5	0 1 1 0 0
//輸出
//1	8
//2	7
//3	5
//4	9
//5	6
//6	2
//7	4
//8	1
//9	0
//10	3
//11	17
//12	15
//13	14
//14	16
//15	12
//16	11
//17	13
//18	10


#include <stdio.h>
main()
{
  int row, column;
  int array[22][22]= {0};
  int i, j;
  int d_row, d_column, p_row, p_column;
  int temp;

  scanf("%d%d", &column, &row);

  for(i = 1; i <= row; i++)
  for(j = 1; j <= column; j++)
    scanf("%d", &array[i][j]);

  for(j = 1; j <= column; j++)
    array[row+1][j] = j - 1;

  for(i = row; i >= 1; i--)
    array[i][column+1] = row + column - i;

  for(j = column; j >= 1; j--)
    array[0][j] = row + 2* column - j;

  for(i = 1; i <= row; i++)
    array[i][0] = row + 2 * column + i - 1;

  printf("\nArray:\n");
  for(i = 0; i <= row + 1; i++) {
    printf("\n");
    for(j = 0; j <= column + 1; j++)
      printf("%2d ", array[i][j]);
  }
  printf("\n");



  // print result
  for(j = 1; j <= column; j++) {
    d_row = -1;
    d_column = 0;
    p_row = row + 1;
    p_column = j;
    do {
      p_row += d_row;
      p_column += d_column;
      if(array[p_row][p_column] != 0) {temp = d_row; d_row = -d_column; d_column = -temp;}
    } while(p_row > 0 && p_row < row + 1 && p_column > 0  && p_column < column + 1);
    printf("%d\n", array[p_row][p_column]);
  }
  //  array[row+1][j] = j;

  for(i = row; i >= 1; i--) {
    d_row = 0;
    d_column = -1;
    p_row = i;
    p_column = column + 1;
    do {
      p_row += d_row;
      p_column += d_column;
      if(array[p_row][p_column] != 0) {temp = d_row; d_row = -d_column; d_column = -temp;}
    } while(p_row > 0 && p_row < row + 1 && p_column > 0  && p_column < column + 1);
    printf("%d\n", array[p_row][p_column]);
  }
   // array[i][column+1] = row + column - i + 1;

  for(j = column; j >= 1; j--) {
    d_row = 1;
    d_column = 0;
    p_row = 0;
    p_column = j;
    do {
      p_row += d_row;
      p_column += d_column;
      if(array[p_row][p_column] != 0) {temp = d_row; d_row = -d_column; d_column = -temp;}
    } while(p_row > 0 && p_row < row + 1 && p_column > 0  && p_column < column + 1);
    printf("%d\n", array[p_row][p_column]);
  }
    //array[0][j] = row + 2* column - j + 1;

  for(i = 1; i <= row; i++) {
    d_row = 0;
    d_column = 1;
    p_row = i;
    p_column = 0;
    do {
      p_row += d_row;
      p_column += d_column;
      if(array[p_row][p_column] != 0) {temp = d_row; d_row = -d_column; d_column = -temp;}
    } while(p_row > 0 && p_row < row + 1 && p_column > 0  && p_column < column + 1);
    printf("%d\n", array[p_row][p_column]);
  }
    //array[i][0] = row + 2 * column + i;
  
}
