#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define WORDLEN 80

typedef struct {
	char str[WORDLEN];
	int len;
	int upper;
	int vowel;
}Word;

typedef Word Datatype;

typedef struct {
	Datatype **pt_data;
	int size;
	int member;
}Array;

void initArray (Array *wa)
{
	wa->pt_data = (Datatype **) malloc (sizeof(Datatype *));
	assert(wa->pt_data != NULL);
	wa->size = 1;
	wa->member = 0;
}

void built_data (Datatype *data, const char *s)
{
	int i;
	char c;
	strncpy(data->str, s, 80);
	data->len = strlen(s);
	data->upper = 0;
	data->vowel = 0;
	for (i = 0; i < WORDLEN && i < data->len; i++) {
		c = s[i];
		if (isupper(c)) data->upper++;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
			data->vowel++;
	}
}

int data_comp(const void *data1, const void *data2)
{
	Datatype **ptr1 = (Datatype **) data1;
	Datatype **ptr2 = (Datatype **) data2;
	//printf("%d\n", (ptr2->upper - ptr1->upper));
	if ((*ptr1)->len != (*ptr2)->len)
		return (*ptr1)->len - (*ptr2)->len;
	if ((*ptr1)->upper != (*ptr2)->upper)
		return (*ptr1)->upper - (*ptr2)->upper;
	if ((*ptr1)->vowel != (*ptr2)->vowel)
		return (*ptr1)->vowel - (*ptr2)->vowel;
	
	return 0;
}

void print_array(Array *wa)
{
	int i;
	for (i = 0; i < wa->member; i++)
		printf("%s\n", wa->pt_data[i]->str);
}

Array *add_Column (Array *wa, Datatype *data)
{
	Datatype **new_ptr;
	int new_size;
	if (wa->member >= wa->size) {
		new_size = wa->size * 2;
		new_ptr = (Datatype **) malloc (sizeof(Datatype *) * new_size);
		assert(new_ptr != NULL);
		memcpy(new_ptr, wa->pt_data, sizeof(Datatype *) * wa->size);
		free(wa->pt_data);
		wa->pt_data = new_ptr;
		wa->size = new_size;
	}
	wa->pt_data[wa->member++] = data;
}

int main (void)
{
	Array wa;
	Datatype *pt_data;
	char s[WORDLEN];
	initArray(&wa);
	
	while (scanf("%s", s) != EOF) {
		pt_data = (Datatype *) malloc (sizeof(Datatype));
		assert(pt_data != NULL);
		built_data(pt_data, s);
		add_Column(&wa, pt_data);
	}
	qsort(wa.pt_data, wa.member, sizeof(Datatype *), data_comp);
	print_array(&wa);
	return 0;
}
