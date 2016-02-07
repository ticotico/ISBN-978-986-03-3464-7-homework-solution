/*
寫一個程式比較兩個文字檔案。比較的方法是一行一行比較，並列出
不同的行數。一行最多有 m 個字元。
輸入有兩行，分別為兩個檔案的名稱。檔案名稱的長度上限是 n。輸出
為兩個檔案不一樣地方的行數。如果兩個檔案有不同行數，則必須要先
輸出行數較多的檔案名稱，在輸出多幾行。
參數規範: 0 < n, m <= 80
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define max_filename_len 80
#define max_line_len 80

int count_rest_line(FILE *f)
{
	char buf[max_line_len];
	int count = 1;
	while (fgets(buf, max_line_len, f) != NULL)
		count++;
	return count;
}

int main (void)
{
	FILE *fp1, *fp2;
	char file1[max_filename_len];
	char file2[max_filename_len];
	char line1[max_line_len];
	char line2[max_line_len];
	char *cp1, *cp2;
	int cur_line = 0;
	int end_line;
	
	scanf("%s", file1);
	scanf("%s", file2);
	
	fp1 = fopen(file1, "rb");
	assert(fp1 != NULL);
	fp2 = fopen(file2, "rb");
	assert(fp2 != NULL);
	
	cp1 = fgets(line1, max_line_len, fp1);
	cp2 = fgets(line2, max_line_len, fp2);
	while (cp1 != NULL && cp2 != NULL) {
		if (strcmp(line1, line2) != 0)
			printf("%d\n", cur_line);
		cp1 = fgets(line1, max_line_len, fp1);
		cp2 = fgets(line2, max_line_len, fp2);
		cur_line++;
	}
	
	if (cp1 != NULL && cp2 == NULL)
		printf("%s %d\n", file1, count_rest_line(fp1));
	
	if (cp2 != NULL && cp1 == NULL)
		printf("%s %d\n", file2, count_rest_line(fp2));
	
	fclose(fp1);
	fclose(fp2);
	return 0;
}
