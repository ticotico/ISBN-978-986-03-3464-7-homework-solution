/*
寫一個程式選材料。我們有 3 種材料，a、b、c，也有三種貨物
d、e、f。製造一單位的 d 需要 da 單位的 a，db 單位的 b 及
dc 單位的 c。製造一單位的 e 需要 ea 單位的 a，eb 單位的
b 及 ec 單位的 c。製造一單位的 f 需要 fa 單位的 a，fb 單
位的 b 及 fc 單位的 c。假如一個工廠有 A 單位的材料 a，B
單位的材料 b，C單位的材料 c，這個工廠有可能將所有材料剛
好用完而製成商品嗎?
輸入第一行為 da、db、dc。第二行為ea、eb、ec。第三行為fa、
fb、fc。下一行為 n，為工廠的數量，以下 n 行每行為工廠所有
的材料 a、b、c 數量 A、B、C。輸出為 n 行。這個工廠有可能將
所有材料剛好用完而製成商品則輸出 yes，否則輸出 no。
*/

#include <stdio.h>

int run_out (int a, int b, int c, int material[3][3])
{
	//printf("call %d %d %d\n", a, b, c);
	int result = 0;
	int lack = 1;
	int i;
	
	if (a == 0 && b == 0 && c == 0)
		return 1;
	
	for (i = 0; i < 3; i++)
		if (a >= material[i][0] &&
			b >= material[i][1] &&
			c >= material[i][2])
			lack = 0;
	if (lack == 1)
		return 0;
	
	for (i = 0; i < 3; i++)
		if (run_out(a - material[i][0], 
					b - material[i][1],
					c - material[i][2],
					material))
			result = 1;
	
	return result;
	
}

int main (void)
{
	int i, a, b, c, n;
	int material[3][3];
	for (i = 0; i < 3; i++)
		scanf("%d%d%d", &(material[i][0]), &(material[i][1]), &(material[i][2]));
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (run_out(a, b, c, material))
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}
