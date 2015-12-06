//P教授提出了一種新的排序方法稱為"psort"，psort比較兩個數字
//的方法是從最右邊的數字筆到最左邊的數字。例如 19 大於 21，
//因為 9 大於 1。而 119 大於 19，因為比完9 和 1 之後 119 還有
//數字，而 119 沒有，現給定 n 個數字，請使用 psort 進行排序。
//輸入第一行為數字個數 n 。以下 n 行為要排序的數字。輸出即為
//n 個數字由小到大的排序結果。
//參數規範 0 < n <= 10000。

#include <stdio.h>
main()
{
  int n, a[10001];
  int i, j, temp;
  int b, c;
  int flag_swap, power;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(i = 0; i < n - 1; i++)
  for(j = i + 1; j < n; j++) {
    b = a[i];
    c = a[j];
    flag_swap = 0;
    power = 1;
    do {
      power *= 10;
      if(b % power > c % power) flag_swap = 1;
      else if (b % power < c % power) flag_swap = 2;
    } while(flag_swap == 0 && b != c);

    if(flag_swap == 1) {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }

  for(i = 0; i < n; i++)
    printf("%d\n", a[i]);
}
