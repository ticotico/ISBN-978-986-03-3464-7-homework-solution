//有一輛卡車行駛在沙漠中，我們想知道他最後的位置。卡車最初
//是在位置 (0,0) 以每小時 10公里向北移動。卡車會收到一系列
//依照時間戳記排序的命令， 1 表示「向左轉」， 2 表示「向右
//轉」， 3 表示「停止」，所以我們知道該命令是何時發出的。最
//後一個命令一定是「停止」。我們另外還假設，這輛卡車非常靈
//活，所以他可以瞬間轉彎。
//以下列輸入為例。卡車在時間 5 的時候收到一個「向左轉」的命
//令 1，在時間 10 收到一個 「向右轉」的命令 2 ，在時間 15 
//收到一個停止的命令 3。那麼最後在時間 15 的時候，卡車的位
//置將在 (-50,100) 。程式只需輸出卡車的最後位置。第一行是 x
//座標，第二行是 y 座標。

#include <stdio.h>
main()
{
  int command = 1, time_start = 0, time_end;
  int direction = 1; //0 right, 1 up, 2 left, 3 dowm
  int x = 0, y = 0;
  do {
    scanf("%d", &time_end);
    switch (direction) {
      case 0:
        x += (time_end - time_start) * 10;
        break;
      case 1:
        y += (time_end - time_start) * 10;
        break;
      case 2:
        x -= (time_end - time_start) * 10;
        break;
      case 3:
        y -= (time_end - time_start) * 10;
        break;
      default:
        printf("error\n");
    }
    scanf("%d", &command);
    if (command == 1) {
      if (direction == 3) direction  = 0;
      else direction++;
    } else if (command == 2) {
      if (direction == 0) direction = 3;
      else direction--;
    }

    time_start = time_end;

  } while (command == 1 || command == 2);

  printf("%d\n", x);
  printf("%d\n", y);
}
