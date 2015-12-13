//寫一個程式決定一個 n 個點中距離原點第三近的點，輸入第一行
//為點數 n。以下 n 行每行代表一個點的 x, y, z 座標。座標值
//均以 double 表示。輸出是第幾個點，(由1算起) 是距原點第三
//近的點。注意  n 可能很大所以不可能將所有的點存起來在做決定
//參數規範: 3 <= n <= 1000000

#include <stdio.h>
main()
{
  int m[5] = {0, -3, -2, -1};
  double d[5] = {0.0, -3.0, -2.0, -1.0};
  double x, y, z, sumd, tempd;
  int i, j, k, n, tempm;

  scanf("%d", &n);
  for(i = 1; i <= 3; i++) {
    scanf("%lf%lf%lf", &x, &y, &z);
    m[i] = i;
    d[i] = x*x + y*y + z*z;
  }



  for(k = 4; k <= n; k++) {
    scanf("%lf%lf%lf", &x, &y, &z);
    d[4] = x*x + y*y + z*z;
    m[4] = k;
    
    for(i = 1; i <= 3; i++)
      for(j = i + 1; j <= 4; j++) {
        if(d[i] > d[j]) {
          tempd = d[i];
          d[i] = d[j];
          d[j] = tempd;
          tempm = m[i];
          m[i] = m[j];
          m[j] = tempm;
        }
      }
  }

  printf("%d\n", m[3]);
}
