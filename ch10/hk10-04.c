/*
寫一個程式將輸入 C++ 程式的註解完全刪除。C++程式的註解是
由 // 一直到行尾。為求簡單起見我們假設任何 //開始的程式
部分都是註解，所以註解不會出現在字串常數中。
輸入是一個C++程式。程式必須處理所有的字元直到EOF。
輸出是將註解完全刪除的輸入程式。
*/

#include <stdio.h>
int main(void)
{
	char c;
	int flag = 0;
	while (scanf("%c", &c) != EOF) {
		if (flag == 0 && c =='/')
			flag = 1;
		else if (flag == 1 && c == '/')
			flag = 2;
		else if (flag ==1 && c != '/') {
			flag = 0;
			printf("/");
		}
		else if (flag == 2 && c == '\n')
			flag = 0;
		
		if (flag == 0 && c != '/')
			printf("%c", c);
	}
	
	return 0;
}
