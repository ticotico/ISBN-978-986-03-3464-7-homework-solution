//寫一個程式計算金屬板的弱點，給定一個金屬板，我們想知道這一
//金屬板的弱點在何處。首先我們在這個金屬板的各個部位做強度的
//採樣，採樣的結果存在一個 n 乘 m 二維福點數陣列中。
//從已往的經驗我們知道一個弱點具有一個特性，就是弱點強度是以
//該點為中心附近 k 乘 k 個點中最小的。現給定金屬板的寬度 n，
//和長度 m ，n 乘 m 的強度採樣結果以及 k ，請找出所有弱點的
//座標。
//輸入第一行為金屬板的寬度 n 、長度 m 及 k。以下 n 行每行有
//m個浮點數，代表該位置的強度。輸出每一行維一個弱點的位置，
//先輸出由上到下的行數，在輸出該行裝第幾個點。如果有許多弱點
//，輸出的順序是由上到下，由左到右。
//參數規範: 0 < n, m <= 300, 0 < k <= min(m, n ,5)，同時 k 是奇數

#include <stdio.h>
main()
{
  int n, m, k, halfk;
  double array[302][302];
  int i, j, row, column;
  int flag_min;
  scanf("%d%d%d", &n, &m, &k);
  
  for(i = 1; i <= n; i++)
  for(j = 1; j <= m; j++)
    scanf("%lf", &array[i][j]);

  k = (k < m) ? k : m;
  k = (k < n) ? k : n;
  if (k % 2 == 0) k--;
  halfk = (k - 1) / 2;

  for(i = 1; i <= n; i++)
  for(j = 1; j <= m; j++) {
    flag_min = 1;
    for(row = ((i > halfk) ? (i - halfk) : 1);
        row <= ((i + halfk <= n) ? (i + halfk) : n); row++)
    for(column = ((j > halfk) ? (j - halfk) : 1);
        column <= ((j + halfk <= m) ? (j + halfk) : m); column++)
          if(array[row][column] < array[i][j]) flag_min = 0;
    if(flag_min == 1) printf("%d %d\n", i, j);
  }
}
