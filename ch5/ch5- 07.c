//模擬兩顆球在邊長x,y的盒子內做運動。

#include <stdio.h>
main()
{
  int x, y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, t;
  int i ;
  scanf("%d%d%d%d%d%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);

  if (!(0 < x) || !(x < 20) || !(0 < y) || !(y < 20)) printf("Error: wrong size for box \n");
  else if (!(0 < x1) || !(x1 < x) || !(0 < y1) || !(y1 < y)) printf("Error: ball 1 is outside box\n");
  else if (!(0 < x2) || !(x2 < x) || !(0 < y2) || !(y2 < y)) printf("Error: ball 2 is outside box\n");
  else if ((x1 == x2) && (y1 == y2)) printf("Error: two balls at the same origin point\n");
  else if (!(dx1 == 1) && !(dx1 == -1)) printf("Error: dx1 shuld be 1 or -1\n");
  else if (!(dy1 == 1) && !(dy1 == -1)) printf("Error: dy1 shuld be 1 or -1\n");
  else if (!(dx2 == 1) && !(dx2 == -1)) printf("Error: dx2 shuld be 1 or -1\n");
  else if (!(dy2 == 1) && !(dy2 == -1)) printf("Error: dy2 shuld be 1 or -1\n");
  else if (t < 0) printf("t must be positive or zero\n");
  else
  {
      printf(" t (x1,y1) (x2,y2) (dx1,dy1) (dx2,dy2)\n");
    for (i = 0; i <= t; i++) {
      //印出時間、兩顆球的目前位置及速度
      printf("%2d (%2d,%2d) (%2d,%2d) (%3d,%3d) (%3d,%3d)\n",
        i, x1, y1, x2, y2, dx1, dy1, dx2, dy2);

      //兩顆球的新位置(做運動後)
      x1 += dx1;
      y1 += dy1;
      x2 += dx2;
      y2 += dy2;

      //如果球碰到牆壁，運動方向改驗
      if (x1 == 0 || x1 == x) dx1 *= -1;
      if (y1 == 0 || y1 == y) dy1 *= -1;
      if (x2 == 0 || x2 == x) dx2 *= -1;
      if (y2 == 0 || y2 == y) dy2 *= -1;

      //如果兩顆球在同時間同一位置，發生碰撞，運動方向改變
      if (x1 == x2 && y1 == y2) {
        if (dx1 != dx2) { dx1 *= -1; dx2 *= -1;}
        if (dy1 != dy2) { dy1 *= -1; dy2 *= -1;}
      }
    }
  }
}

      
