//同上題，但計算每一位同學的最高及最低成績，
//及每一門課的最高及最低成績

#include <stdio.h>
main()
{
  int s, c, i, j, max, min, a[101][101];
  scanf("%d", &s);
  scanf("%d", &c);
  for(i = 0; i < s; i++)
    for(j = 0; j < c; j++)
      scanf("%d", &a[i][j]);


  for(i = 0; i < s; i++) {
    max = 0;
    min = 100;
    for(j = 0; j < c; j++) {
      max = (max > a[i][j]) ? max : a[i][j];
      min = (min < a[i][j]) ? min : a[i][j];
    }
    printf("%d %d\n", max, min);
  }

  for(j = 0; j < c; j++) {
    max = 0;
    min = 100;
    for(i = 0; i < s; i++) {
      max = (max > a[i][j]) ? max : a[i][j];
      min = (min < a[i][j]) ? min : a[i][j];
    }
    printf("%d %d\n", max, min);
  }
}
