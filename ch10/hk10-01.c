/*
寫一個程式計算輸入各種字元的數目。需要計算數目的字元為
數字、字母、子音和母音。母音的定義是不分大小寫的a、e、
i、o、u、程式必須處理所有的字元直到EOF
*/

#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int n_digit = 0, n_alpha = 0;
	int n_vowel = 0, n_consonant = 0;
	char c;
	while (scanf("%c", &c) != EOF) {
		if (isdigit(c))
			n_digit++;
		else if (isalpha(c)) {
			n_alpha++;
			if (c == 'A' || c == 'E' || c == 'I' ||
				c == 'O' || c == 'U' || c == 'a' ||
				c == 'e' || c == 'i' || c == 'o' ||
				c == 'u')
				n_vowel++;
			else
				n_consonant++;
		}
	}
	printf("%d\n%d\n", n_digit, n_alpha);
	printf("%d\n%d\n", n_vowel, n_consonant);
	return 0;
}
