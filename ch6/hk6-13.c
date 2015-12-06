//現有一個 n 乘 n 乘 n 的立方體，立方體的每一小格都有一個從 1
//到 n^3 不同的數字。 我們將這 n^3 個號碼一次一個隨機抽出，如
//果已抽出數字形成一行、一列、一直行或一個對角線，則稱為"bingo"
//。注意一個對角線可能從一個角到任意另一個角。請檢查一序列數字
//何時出現"bingo"

//輸入的第一行是 n ，以下 n^3 個數字是出現在 n 乘 n 個方陣的數字
//，出現的順序是按行按列逐個出現。再以下 n^3 個數字是 n^3 個號碼
//隨機抽出的順序，每行有 n 個數字。輸出只有一個數字，就是在哪一個
//數字出現時出現第一次"bingo"，

#include <stdio.h>
int main()
{
  int n;
  int i, j, k;
  int a, b, c;
  int x, y, z;
  int number[10][10][10], find_series[1000], is_find[10][10][10] = {0};
  int flag_bingo = 0, flag_find;
  int sum_line;

  scanf("%d", &n);

  if(n <= 0 || n >= 10) return 0;

  for(i = 0; i < n; i++)
  for(j = 0; j < n; j++)
  for(k = 0; k < n; k++)
    scanf("%d", &number[i][j][k]);

  for(a = 0; a < n * n * n; a++)
    scanf("%d", &find_series[a]);

  for(a = 0; a < n * n * n && flag_bingo == 0; a++) {

//判斷方塊中的哪一個點被找到
    flag_find = 0;
    for(i = 0; i < n && flag_find == 0; i++)
    for(j = 0; j < n && flag_find == 0; j++)
    for(k = 0; k < n && flag_find == 0; k++)
      if(flag_find == 0 && find_series[a] == number[i][j][k]) {
        is_find[i][j][k] = 1;
        flag_find = 1;
        x = i;
        y = j;
        z = k;
      }
    if(x == n && y == n && z == n) {
      printf("error: cannot find number\n");
      printf("find_series[%d] = %d\n", a, find_series[a]);
      return 0;
    }

    for(b = 1; b <= 13; b++) {
      sum_line = 0;
      switch(b) {
      case 1:
        j = y;
        k = z;
        for(i = 0; i < n; i++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 2:
        i = x;
        k = z;
        for(j = 0; j < n; j++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 3:
        i = x;
        j = y;
        for(k = 0; k < n; k++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 4:
        k = z;
        for(i = x, j = y;i > 0 && j > 0; i--, j--);
        for(; i <= n && j <= n; i++, j++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 5:
        k = z;
        for(i = x, j = y;i > 0 && j < n; i--, j++);
        for(; i <= n && j >= 0; i++, j--) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 6:
        j = y;
        for(i = x, k = z;i > 0 && k > 0; i--, k--);
        for(; i <= n && k <= n; i++, k++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 7:
        j = y;
        for(i = x, k = z;i > 0 && k < n; i--, k++);
        for(; i <= n && k >= 0; i++, k--) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 8:
        i = x;
        for(k = z, j = y;k > 0 && j > 0; k--, j--);
        for(; k <= n && j <= n; k++, j++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 9:
        i = x;
        for(k = z, j = y;k > 0 && j < n; k--, j++);
        for(; k <= n && j >= 0; k++, j--) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 10:
        for(i = x, j = y, k = z; i > 0 && j > 0 && k > 0;i--, j-- ,k--);
        for(; i <= n && j <= n && k <= n; i++, j++, k++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 11:
        for(i = x, j = y, k = z; i < n && j > 0 && k > 0;i++, j-- ,k--);
        for(; i >= 0 && j <= n && k <= n; i--, j++, k++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 12:
        for(i = x, j = y, k = z; i < n && j < n && k > 0;i++, j++ ,k--);
        for(; i >= 0 && j >= 0 && k <= n; i--, j--, k++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      case 13:
        for(i = x, j = y, k = z; i > 0 && j < n && k > 0;i--, j++ ,k--);
        for(; i <= n && j >= 0 && k <= n; i++, j--, k++) sum_line += is_find[i][j][k];
        if(sum_line == n) flag_bingo = 1;
        break;
      }
    }

  }

  printf("%d\n", find_series[a - 1]);

  return 0;
}
