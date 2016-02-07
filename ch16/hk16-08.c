/*
寫一個程式加密檔案，我們可以將整個檔案的內容視為一個巨大的
無符號整數，檔案的開頭是高位元(most significant bit)，檔案
的結尾是低位元(leat significant bit)。首先我們對這個龐大的
數字做移位。使用者會決定是向左或向右移，以及要移幾個位元，
之後我們在使用一個數字 e 對移位之後的每一個字元作互斥或
(exclusive or)。最後將結果寫進輸出檔案。
輸入有四行: 第一行是要加密的檔案名稱，以及要寫入加密結果的
檔案名稱。檔案名稱沒有空白且長度為 n。輸入檔案的長度上限為
m 位元組。第二行是移位方向，可以是 L(向左移)或是 R(向右移)
。第三行是要移位的位元數 s。第四行是互斥或的數字。
參數規範: 0 < n <= 80, 0 < m <= 65536, 0 <= s < 8m
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FILENAME_SIZE 80

void print_binary(unsigned char n)
{
	unsigned char i;
	for (i = 128; i; i >>= 1) printf("%d", n & i ? 1 : 0);
}

int get_file_size(char *filename, char *mode)
{
	long start, end;
	FILE *fp;
	fp = fopen(filename, mode);
	assert(fp != NULL);
	start = ftell(fp);
	fseek(fp, 0, SEEK_END);
	end = ftell(fp);
	fclose(fp);
	return (int) (end - start);
}

void array_right_shift_bit(unsigned char *array, int array_size, int shift)
{
	unsigned char mask = (1 << shift) - 1;
	unsigned char cur_tail, next_tail = 0;
	int i;
	unsigned char tail_bit = (array[array_size - 1] & mask) << (8 - shift);
	
	for (i = 0; i < array_size; i++) {
		cur_tail = (array[i] & mask) << (8 - shift);
		array[i] >>= shift;
		array[i] |= next_tail;
		next_tail = cur_tail;
	}
	
	array[0] |= tail_bit;
}

void array_left_shift_bit(unsigned char *array, int array_size, int shift)
{
	unsigned char mask = (255 >> shift) << shift;
	unsigned char cur_head, next_head = 0;
	int i;
	unsigned char head_bit = (array[0] & mask) >> (8 - shift);
	
	for (i = array_size - 1; i >= 0; i--) {
		cur_head = (array[i] & mask) >> (8 - shift);
		array[i] <<= shift;
		array[i] |= next_head;
		next_head = cur_head;
	}
	
	array[array_size - 1] |= head_bit;
}

void array_right_shift_byte(unsigned char *array, int array_size, int shift_byte)
{
	int i;
	unsigned char *temp;
	temp = (unsigned char *) malloc (shift_byte);
	assert(temp != NULL);
	for (i = 0; i < shift_byte; i++)
		temp[i] = array[array_size - shift_byte + i];
	for (i = array_size - 1; i >= shift_byte; i--)
		array[i] = array[i - shift_byte];
	for (i = 0; i < shift_byte; i++)
		array[i] = temp[i];
	free(temp);
}

void array_left_shift_byte(unsigned char *array, int array_size, int shift_byte)
{
	int i;
	unsigned char *temp;
	temp = (unsigned char *) malloc (shift_byte);
	assert(temp != NULL);
	for (i = 0; i < shift_byte; i++)
		temp[i] = array[i];
	for (i = 0; i < array_size - shift_byte; i++)
		array[i] = array[i + shift_byte];
	for (i = 0; i < shift_byte; i++)
		array[array_size - shift_byte + i] = temp[i];
	free(temp);
}

void array_shift(unsigned char *array, int array_size, char LR, int s)
{
	int shift_bit = s % 8;
	int shift_byte = s / 8;
	if (LR == 'L') {
		array_left_shift_bit(array, array_size, shift_bit);
		array_left_shift_byte(array, array_size, shift_byte);
	}
	else if (LR == 'R') {
		array_right_shift_byte(array, array_size, shift_byte);
		array_right_shift_bit(array, array_size, shift_bit);
	}
	else exit(-1);
}

void array_all_unit_xor(unsigned char *array, int array_size, int e)
{
	int i;
	for (i = 0; i < array_size; i++)
		array[i] ^= e;
}

int main (void)
{

	char file_in[FILENAME_SIZE], file_out[FILENAME_SIZE];
	FILE *fpin, *fpout;
	char LR;
	int s, e;
	int file_size;
	int i;
	unsigned char *pt_uc;
	
	scanf("%s%s", file_in, file_out);
	getchar();
	scanf("%c", &LR);
	scanf("%d%d", &s, &e);
	
	file_size = get_file_size(file_in, "rb");
	pt_uc = (unsigned char *)malloc(file_size);
	assert(pt_uc != NULL);
	
	fpin = fopen(file_in, "rb");
	assert(fpin != NULL);
	fread(pt_uc, sizeof(unsigned char), file_size, fpin);
	fclose(fpin);
	
	array_shift(pt_uc, file_size, LR, s);
	array_all_unit_xor(ptuc, file_size, e);
	
	fpout = fopen(file_out, "wb");
	assert(fpout != NULL);
	
	fwrite(pt_uc, sizeof(unsigned char), file_size, fpout);
	fclose(fpout);
	
	free(pt_uc);

	return 0;
}
