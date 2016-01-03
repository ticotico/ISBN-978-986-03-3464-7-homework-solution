/*
寫一個程式把英文名詞依下列規則變成複數型，
請注意這些規則僅適用本題，並非100%準確的英文。
1.如果名詞以ch、sh、s、z、x 結尾，則加 es，如
  box的複數形式是 boxes。
2.如果以 y 結尾，我們要檢查 y 之前的字母。如果
  是母音，即 a、e、i、o、u 則只要添加一個 S 。
  例如 toy 的複數是 toys，如果 y 之前不是母音，
  那麼我們就用 ies 取代 y。例如 story 的複數是
  stories，
3.其他名詞只需添加 s。
輸入每一行都是由小寫字母構成且長度不超過 n 的英
文字。城市必須處理所有的輸入直到 EOF。輸出為輸入
英文字以上述規則建立的複數型。
參數規範: 0 < n <= 80
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[83];
	char c1, c2;
	while(scanf("%s", string) != EOF) {
		c1 = string[strlen(string) - 1];
		c2 = string[strlen(string) - 2];
	
		switch (c1) {
			case 'x': case 's': case 'z':
				strcat(string, "es");
				break;
			case 'h':
				if (c2 == 's' || c2 == 'c')
					strcat(string, "es");
				else
					strcat(string, "s");
				break;
			case 'y':
				if (c2 == 'a' || c2 == 'e' || c2 == 'i' ||
					c2 == 'o' || c2 == 'u')
						strcat(string, "s");
				else {
					string[strlen(string) - 2] = '\0';
					strcat(string, "ies");
				}
				break;
			default:
				strcat(string, "s");
		}
		printf("%s\n", string);
	}
	return 0;
}
