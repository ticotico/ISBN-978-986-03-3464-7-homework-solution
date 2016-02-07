/*
寫一個程式來讀取 sample.htm 文件並找出所有連結。我們假設
連接格式均為 href="URL"，=之前或之後沒有空格，且一個URL不
會跨越多行。每一行長度上限為 n。
輸入在 sample.htm 文件內，輸出為所有連接的 URL。一個 URL
一行。
參數規範: 0 < n <= 200000, 0 < m <= 100
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define max_line_len 200000

int main (void)
{
	const char filename[] = "sample.htm";
	char line[max_line_len];
	FILE *fp;
	char out_buf[48];
	char *find_link;
	
	fp = fopen(filename, "rt");
	assert(fp != NULL);
	
	while(fgets(line, max_line_len, fp) != NULL)
		if ((find_link = strstr(line, "href=")) != NULL) {
			find_link += 6;
			while (*find_link != '"')
				putchar(*find_link++);
			putchar('\n');
		}
	
	fclose(fp);
	
	return 0;
}
