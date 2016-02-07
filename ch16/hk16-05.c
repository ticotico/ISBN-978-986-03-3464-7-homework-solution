/*
編寫一個程式替換檔案中的特定字串。城市打開輸入檔案並讀取內容
並搜索特定字串 (pattern)。當找到一個特定字串時，程式會將其代
換成替換字串 (replacement)。置換過的檔案內容會寫入輸出檔案。
輸入有四行，分別為: 輸入檔案名稱、輸出檔案名稱、特定字串及替
換字串。所有的字串長度上限為 m。輸入檔案一行的上限為 n。
參數規範: 0 < n <= 256, 0 < m <= 80。
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define len_m 80
#define len_n 256

char *replace_once(char *str, char *pattern, char *replace)
{
	char buf[len_n];
	int len_pattern = strlen(pattern);
	char *rep = strstr(str, pattern);
	
	strncpy(buf, str, rep - str);
	buf[rep - str] = '\0';
	strcat(buf, replace);
	strcat(buf, rep + len_pattern);
	
	strcpy(str, buf);
	return str;
}

int main (void)
{
	FILE *fpin, *fpout;
	char filename_in[len_m], filename_out[len_m];
	char pattern[len_m], replacement[len_m];
	char read_line_buf[len_n]; 
	
	scanf("%s", filename_in);
	scanf("%s", filename_out);
	scanf("%s", pattern);
	scanf("%s", replacement);
	
	fpin = fopen(filename_in, "rb");
	assert(fpin != NULL);
	fpout = fopen(filename_out, "wb");
	assert(fpout != NULL);
	
	while (fgets(read_line_buf, len_n, fpin) != NULL) {
		while(strstr(read_line_buf, pattern) != NULL)
			replace_once(read_line_buf, pattern, replacement);
			
		fputs(read_line_buf, fpout);
	}
	
	fclose(fpin);
	fclose(fpout);
	
	return 0;
}
