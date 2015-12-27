/*
寫一個程式計算輸入文章中的句子數。為求簡單起見我們假設
一個句子的結束必定是一個句點。但是為了避免像 "Mr."或是
"i.e."這樣的問題，我們規定句子後面必須有兩個連續空白，
或是句點後面就是換行，或是最後一個句點到 EOF 之前都只有
空白或換行，才算是一個句子。
輸入是一段文章。程式必須處理所有的字元直到 EOF。輸出是
文章中的句子數。
*/
#include <stdio.h>
int main (void)
{
	int count = 0;
	int flag = 0;
	char c;
	while (scanf("%c", &c) != EOF) {
		if (c == '.')
			flag = 1;
		
		if (flag == 1 || flag == 2) {
			if (c == '\n') {
				count++;
				flag = 0;
			} else if (c == ' '){
				flag++;
			}
			if (flag == 3) {
				count++;
				flag = 0;
			}
		}
	}
	if (flag >= 1)
		count++;
	printf("%d\n", count);
	return 0;
}
