//寫一個程式計算平均成績。假設有 s 位同學修習相同的 c 門課程，
//請計算每一位同學的平均成績，以及每一門課程所有學生的平均成績
//。輸入第一行為 s 及 c 。以下 s 行每行代表一位學生的修課成績。
//每一行有 c 個數字，第 i 個數字代表學生修第 i 門課的成績。
//輸出有 s+c 行。前 s 行代表 s 位學生的平均成績，後 c 行代表
//c 門課所有學生的平均成績。
//參數規範 0 < s <= 100, 0 < c <= 100

#include <stdio.h>
main()
{
  int s, c, i, j, sum, a[101][101];
  scanf("%d", &s);
  scanf("%d", &c);
  for(i = 0; i < s; i++)
    for(j = 0; j < c; j++)
      scanf("%d", &a[i][j]);

  for(i = 0; i < s; i++) {
    sum = 0;
    for(j = 0; j < c; j++)
      sum += a[i][j];
    printf("%d\n", sum / c);
  }

  for(j = 0; j < c; j++) {
    sum = 0;
    for(i = 0; i < s; i++)
      sum += a[i][j];
    printf("%d\n", sum / s);
  }
}
