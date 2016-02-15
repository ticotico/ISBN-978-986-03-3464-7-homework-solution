#include <stdio.h>
#include <assert.h>

typedef struct {
	char c1;
	char c2;
	long int n_byte;
}CompareFile;

#define max_filename_len 80

#ifndef VERBOSE
#define OUTPUT_printf(cf) printf("%04ld\n", cf.n_byte);
#else
#define OUTPUT_printf(cf) printf("offset %04ld: %02x != %02x\n", cf.n_byte, cf.c1, cf.c2);
#endif //VERBOSE

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
	CompareFile cf;
	FILE *fp1, *fp2;
	
	scanf("%s", file1);
	scanf("%s", file2);
	
	fp1 = fopen(file1, "rb");
	assert(fp1 != NULL);
	fp2 = fopen(file2, "rb");
	assert(fp2 != NULL);
	
	cf.n_byte = 0;
	cf.c1 = fgetc(fp1);
	cf.c2 = fgetc(fp2);
	while (cf.c1 != EOF && cf.c2 != EOF) {
		if (cf.c1 != cf.c2)
			OUTPUT_printf(cf); //use macro
		cf.c1 = fgetc(fp1);
		cf.c2 = fgetc(fp2);
		cf.n_byte++;
	}
	if (cf.c1 == EOF && cf.c2 != EOF)
		printf("%s %ld\n", file2, tail_len(fp2));
	
	if (cf.c2 == EOF && cf.c1 != EOF)
		printf("%s %ld\n", file1, tail_len(fp1));
	
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
