/*
寫一個程式生成符合特定模式的字串，並按字典順序輸出。
輸入是一個長度為 n 的模式字串 s，模式字串只包含小寫字母、
*、[和]。一個 * 可以匹配任何母音 a、e、i、o、u，一對[和]
與其間的小寫字母可以匹配任何出現在[]的字元，而且只有小寫
字母可以出現在[和]之間，也就是說，[和]之間不會有 *、[或是]
，而且出現在[和]之間的小寫字母不會重複。
輸出是符合模式字串 s 的所有字串，而且按字母順序排序。
參數規範: 0 < n <= 32
*/

#include <stdio.h>
int prt_str (char *set)
{
	static char print_buf[32];
	static int len = 0;
	int temp_len;
	
	if (*set == '\0') {
		printf("%s\n", print_buf);
		return len;
	}
	
	if (*set == '*') {
		temp_len = len;
		char aeiou[] = "aeiou";
		int i;
		
		for (i = 0; i < 5; i++) {
			print_buf[temp_len] = aeiou[i];
			len = temp_len + 1;
			prt_str(set+1);
		}
	}
	else if (*set == '[') {
		int offset = 0;
		int i, j;
		char sort[26], tmp_c;
		
		while (*(set + offset + 1) != ']') {
			sort[offset] = *(set + offset + 1);
			offset++;
		}
		
		for (i = 1; i < offset; i++)
			for (j = 0; j < i; j++)
				if (sort[i] < sort[j]) {
					tmp_c = sort[i];
					sort[i] = sort[j];
					sort[j] = tmp_c;
				}
		
		temp_len = len;
		
		for (i = 0; i < offset; i++) {
			print_buf[temp_len] = sort[i];
			len = temp_len + 1;
			prt_str(set + offset + 2);
		}
	}
	else {
		print_buf[len] = *set;
		len++;
		prt_str(set+1);
	}
	
	
	return 0;
}

int main (void)
{
	char str[32];
	scanf("%s", str);
	prt_str(str);
	return 0;
}
