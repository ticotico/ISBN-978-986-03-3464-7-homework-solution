//寫一個程式模擬車輛在六角形網格中行進。
//六角形網格的方向行進代碼:
//0	12點鐘方向
//1	2點鐘方向
//2	4點鐘方向
//3	6點鐘方向
//4	8點鐘方向
//5	10點鐘方向
//我們想計算車輛接受一系列的方向代碼後，與出發點之間的距離。
//這裡兩點的距離是指從一點出發到另一點所需要所需走得最短步數。
//例如車輛移動方向代碼為 0 ，之後為 2 ，那麼距離就是 1，因為這
//輛車就在起點旁邊。

//為了使問題更複雜，我們在地圖上擺設三個陷阱，如果車輛掉進陷阱，
//他就不能繼續前進。請計算在擺放三個陷阱之後，車輛最後距離出發
//點的距離。為了使計算簡單起見，我們假設此時路徑可以通過陷阱。

//輸入有四行。前三行每一行用一序列的移動方向描述一個陷阱，每一
//行一開始試一個整數 n，代表由起點到陷阱的移動方向序列長度。
//然後是 n 個介於0 到 5 的整數，代表如何從起點移動到陷阱的路徑
//方向代碼。

//第四行試車輛移動路徑的方向代碼。一開始試一個整數 m，代表路徑
//長度，接著是 m 個介於 0 到 5 的整數，代表車輛移動路徑的方向
//代碼。

//參數規範: 0 < w <= 1000, 0 < d <= 1000
#include <stdio.h>
main()
{
  int n, command, command_car[10001];
  int trap[3][2];
  int x, y;
  int i, j;
  int flag_in_trap = 0, distance = 0;

  //set trap
  for(i = 0; i < 3; i++) {
    x = 0;
    y = 0;
    scanf("%d", &n);
    for(j = 0; j < n; j++) {
      scanf("%d", &command);
      switch(command) {
        case 0:
        y += 2;
        break;

        case 1:
        x++;
        y++;
        break;

        case 2:
        x++;
        y--;
        break;

        case 3:
        y-= 2;
        break;

        case 4:
        x--;
        y--;
        break;

        case 5:
        x--;
        y++;
        break;

        default:
        printf("Error: illegal input\n");
      }
    }

      trap[i][0] = x;
      trap[i][1] = y;
  }

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &command_car[i]);

  x = 0;
  y = 0;

  for(i = 0; i < n && flag_in_trap == 0; i++) {
      switch(command_car[i]) {
        case 0:
        y += 2;
        break;

        case 1:
        x++;
        y++;
        break;

        case 2:
        x++;
        y--;
        break;

        case 3:
        y-= 2;
        break;

        case 4:
        x--;
        y--;
        break;

        case 5:
        x--;
        y++;
        break;

        default:
        printf("Error: illegal input\n");
      }

    for(j = 0; j < 3; j++)
      if(x == trap[j][0] && y == trap[j][1])
        flag_in_trap = 1;

      
  }

  x = (x > 0) ? x : -x;
  y = (x > 0) ? y : -y;

  while (x != 0 || y != 0) {
    if(x == 0) y -= 2;
    else if(y == 0) {x--; y++;}
    else {x--; y--;}

    distance++;
  }

  printf("%d\n", distance);
}
