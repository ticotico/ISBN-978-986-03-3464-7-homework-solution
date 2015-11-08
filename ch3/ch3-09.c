//作業 3.9 寫一個程式讀入三個整數，分別為ㄧ個長方體的
//高度、寬度及深度。寄萬並輸出其表面積及體積。

#include <stdio.h>
main()
{
  int length, width, height;
  int surface_area, volume;
  scanf("%d", &length);
  scanf("%d", &width);
  scanf("%d", &height);

  surface_area = 2 * (length * width + length * height + width * height);
  volume = length * width * height;

  printf("%d\n", surface_area);
  printf("%d\n", volume);
}
