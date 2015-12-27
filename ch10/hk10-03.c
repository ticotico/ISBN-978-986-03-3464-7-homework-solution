
//寫一個程式將輸入程式的註解完全刪除。為求簡單起見，我們
//假設任何/*開始的程式部分都是註解。而且看到*/就結束。註
//解有不會出現在字串常數中。
//輸入是一個程式。程式必須處以所有的字元直到EOF。
//輸出是將註解完全刪除的輸入程式。


#include <stdio.h>
int main (void)
{
	char c;
	int flag = 0;
	while (scanf("%c", &c) != EOF) {
		if (flag == 0 && c == '/')
			flag = 1;
		else if (flag == 1 && c == '*')
			flag = 2;
		else if (flag == 1 && c != '*') {
			flag = 0;
			printf("/");
			if (c == '/') printf("/");
		}
		else if (flag == 2 && c == '*')
			flag = 3;
		else if (flag == 3 && c == '/')
			flag = 0;
		else if (flag == 3 && c == '*')
			flag = 3;
		else if (flag == 3 && (c != '/' || c != '*'))
			flag = 2;
		
		if (flag == 0 && c != '/')
			printf("%c", c);
	}
	return 0;
}
