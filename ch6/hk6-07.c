//回文是一個至少長度為 1 ，且向前讀或向後讀皆相同的整數序列。
//列如 (1,3,5,3,1)、(1,2,2,1)、(1)都是回文。如果我們連接兩個
//回文就得到一個雙回文。,例如(1,3,5,3,1,1,2,2,1)、(1,3,5,3,1,1)
//都是雙回文。現在給訂一個長度為 n 的整數序列，請找出其中最長的
//雙回文。
//輸入第一行為序列長度 n 。輸入第二行為序列元素。輸出為輸入中最長
//的雙回文。如果最長的雙回文不只一個，則輸出在最後面的。
//參數規範 2 <= n <= 100

#include <stdio.h>
main()
{
  int i, j, k, n, A[101];
  int flag_a, flag_b;
  int max = 0, max_a, max_c;
  int a, b, c;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]); 

  for(a = 0; a < n - 1; a++)
  for(c = a + 1; c < n; c++)
  for(b =a; b <= c; b++) {
    flag_a = 0;
    flag_b = 0;
    for(i = 0; i <= (b + a) / 2 && flag_a == 0; i++)
      if(A[a + i] != A[b - i]) flag_a = 1;
    for(i = 0; i <= (c - b) / 2 && flag_b == 0; i++)
      if(A[b + i] != A[c - i]) flag_b = 1;
    if((flag_a == 0) && (flag_b == 0) && (c - a > max)) {
      max = c - a;
      max_a = a;
      max_c = c;
    }
  }

  for(i = max_a; i <= max_c; i++)
    printf("%d ", A[i]);
  printf("\n");
}
