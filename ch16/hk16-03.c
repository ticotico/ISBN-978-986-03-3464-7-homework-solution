/*
寫一個程式將一個檔案分成數個部分。輸入第一行為要分割的
檔案名稱，檔案名稱長度為 n。輸入第二行為每個分割檔案的
大小 m 位元組，但最後一個檔案長度可能不足 m 位元組。輸
出的檔名是直接在檔名後面加.1, .2，其餘類推。
參數規範: 0 < n <= 80, 0 < m < 1024
*/
#include <stdio.h>
#include <assert.h>

#define max_filename_len 80

int count_files(const char *filename, int nbyte)
{
	FILE *fp;
	long int pos_start, pos_end;
	fp = fopen(filename, "rb");
	assert(fp != NULL);
	
	pos_start = ftell(fp);
	fseek(fp, 0, SEEK_END);
	pos_end = ftell(fp);
	fclose(fp);
	
	return (int)(pos_end - pos_start) / nbyte
		+ (((int)(pos_end - pos_start) % nbyte) != 0);
}

int main(void)
{
	FILE *fp1, *fp2;
	char in_filename[max_filename_len];
	char out_filename[max_filename_len + 2];
	int c;
	int n;
	int file_count;
	int i, j;
	
	scanf("%s", in_filename);
	scanf("%d", &n);
	
	file_count = count_files(in_filename, n);
	fp1 = fopen(in_filename, "rb");
	assert(fp1 != NULL);
	
	for (i = 1; i <= file_count; i++) {
		sprintf(out_filename, "%s.%d", in_filename, i);
		fp2 = fopen(out_filename, "wb");
		assert(fp2 != NULL);
		
		for (j = 0; j < n; j++) {
			c = fgetc(fp1);
			fputc(c, fp2);
		}
		fclose(fp2);
		
	}
	
	fclose(fp1);
	return 0;
}
