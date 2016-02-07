/*
寫一個程式比較兩個二進制檔案。比較的方法是一個位元組接著一個
位元組比較，並列出不同的地方。
輸入有兩行，分別為兩個檔案的檔案名稱。檔案的名稱長度上限為 n
，輸出為兩個檔案不一樣地方的位置 (offset)。如果兩個檔案不一樣
大，必須先輸出比較大的檔案名稱，在輸出多幾個位元組。
參數規範: 0 < n <= 80 
*/

#include <stdio.h>
#include <assert.h>

#define max_filename_len 80

long int tail_len(FILE *f)
{
	long int CUR_po, END_po;
	CUR_po = ftell(f);
	fseek(f, 0, SEEK_END);
	END_po = ftell(f);
	return END_po - CUR_po + (long)1;
}

int main (void)
{
	char file1[max_filename_len];
	char file2[max_filename_len];
	char c1, c2;
	FILE *fp1, *fp2;
	int count = 0;
	
	scanf("%s", file1);
	scanf("%s", file2);
	
	fp1 = fopen(file1, "rb");
	assert(fp1 != NULL);
	fp2 = fopen(file2, "rb");
	assert(fp2 != NULL);
	
	c1 = fgetc(fp1);
	c2 = fgetc(fp2);
	while (c1 != EOF && c2 != EOF) {
		if (c1 != c2)
			printf("%d\n", count);
		c1 = fgetc(fp1);
		c2 = fgetc(fp2);
		count++;
	}
	if (c1 == EOF && c2 != EOF)
		printf("%s %ld\n", file2, tail_len(fp2));
	
	if (c2 == EOF && c1 != EOF)
		printf("%s %ld\n", file1, tail_len(fp1));
	
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
