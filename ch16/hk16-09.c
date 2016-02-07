/*
編寫一個程式決定朋友關係。首先們要定義什麼是人。我們假設有
n 個人，每一個人有一個介於 1 到 n 的整數 id，以及不超過 32
個字元的名字。根據一般定義，朋友是彼此的。
假設你有一個包含所有朋友訊息的二進制檔案 friends。friends
依序包含以下資料:
 系統中的人數 n，占 4 個位元組。
 n 個 struct person的內容。
 系統中的朋友對數 f，占 4 個位元組。
 f 個 struct friends 的內容。
接著你需要從鍵盤讀取一系列的命令，每個命令包含兩個名字。如果
兩個名字為朋友，也就是說，存在一個 struct friends 的內容與兩
個名字相符，則輸出 yes，否則輸出 no。城市必須處理所有的輸入
直到 EOF。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NAME_SIZE 32

typedef struct {
	unsigned int id;
	char name[32];
} Person;

typedef struct {
	unsigned int id1;
	unsigned int id2;
}Friend;

unsigned int name_to_id (const char *name, Person *p, int p_size)
{
	int i;
	for (i = 0; i < p_size; i++)
		if (strcmp(name, p[i].name) == 0)
			return p[i].id;
	return 0;
}

int is_friend(unsigned int id1, unsigned int id2, Friend *f, int f_size)
{
	int i;
	for (i = 0; i < f_size; i++)
		if ((id1 == f[i].id1 && id2 == f[i].id2) ||
			(id2 == f[i].id1 && id1 == f[i].id2))
				return 1;
	return 0;
}

//read file and check if friend
int main (void)
{
	char filename_in[] = "file";
	FILE *fpin;
	unsigned int n, f;
	Person *person;
	Friend *friend;
	char name1[NAME_SIZE], name2[NAME_SIZE];
	unsigned int id1, id2;
	int i;
	
	//open file
	fpin = fopen(filename_in, "rb");
	assert(fpin != NULL);
	
	//read file to get person and friend info
	fread(&n, sizeof(unsigned int), 1, fpin);
	person = (Person *) malloc (n * sizeof(Person));
	assert(person != NULL);
	fread(person, sizeof(Person), n, fpin);
	fread(&f, sizeof(unsigned int), 1, fpin);
	friend = (Friend *) malloc (f * sizeof(Friend));
	fread(friend, sizeof(Friend), f, fpin);
	
	//for (i = 0; i < n; i++) printf("id: %d, %s\n", person[i].id, person[i].name);
	//for (i = 0; i < f; i++) printf("id1 %d id2 %d\n", friend[i].id1, friend[i].id2);
	
	while(scanf("%s %s", name1, name2) == 2) {
		id1 = name_to_id(name1, person, n);
		id2 = name_to_id(name2, person, n);
		//printf("%d %d\n", id1, id2);
		if (is_friend(id1, id2, friend, f))
			printf("yes\n");
		else
			printf("no\n");
		
	}
	
	free(friend);
	free(person);
	fclose(fpin);
}

/*//write input file
int main (void)
{
	FILE *fp;
	unsigned int n = 4, f = 2;
	Person person[4] = {{1, "John"}, {2, "Mary"}, {3, "Tom"}, {4, "Jack"}};
	Friend friend[2] = {{2, 1}, {1, 3}};
	
	fp = fopen("file", "wb");
	assert(fp != NULL);
	fwrite(&n, sizeof(unsigned int), 1, fp);
	fwrite(&person, sizeof(Person), n, fp);
	fwrite(&f, sizeof(unsigned int), 1, fp);
	fwrite(&friend, sizeof(Friend), f,fp);
	
	fclose(fp);	
	return 0;
}
*/
