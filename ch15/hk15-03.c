/*
寫一個程式模擬資料庫服務器。程式首先會讀取數據到資料庫，
然後一次執行一個查詢命令。
輸入的第一部分為資料。第一行為資料筆數 n。以下 n 行一行
一筆資料，資料內容由以下欄位組成。字串長度不超過 m。
 lastname，以字串儲存。
 firstname，以字串儲存。
 ID，以字串儲存。
 salary，以整數 int 儲存。
 age，以整數 int 儲存。
輸入第二部分是SQL查詢命令。第一行是命令的個數 c。命令的
格式如下。
 select field1 field2 ... fieldk where condition
filed 可以是 lastname, firstname, ID, salary, age，並可以
任何順序出現。
condition 為測試條件，條件符合的資料才會被輸出。 condition
的格式為 field operator constant。field為任意欄位。如果比較
欄位是字串，operator可能是 ==、!=。如果比較欄位是數字，
operator 可能是 ==、>或<。
輸出為符合條件的指定欄位。欄位與欄位之間有一個空白。
參數規範: 0 < n <= 50, 0 < m <= 80, 0 < c <= 100
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int lastname;
	int firstname;
	int ID;
	int salary;
	int age;
	
}SWprint;

typedef struct {
	char lastname[80];
	char firstname[80];
	char ID[80];
	int salary;
	int age;
	SWprint isprint;
	
}PersonInfo;

void inputPersonInfo (PersonInfo *ptr)
{
	scanf("%s", ptr->lastname);
	scanf("%s", ptr->firstname);
	scanf("%s", ptr->ID);
	scanf("%d", &(ptr->salary));
	scanf("%d", &(ptr->age));
	
	return;
}

void printPersonInfo (PersonInfo *ptr)
{
	if ((ptr->isprint).lastname)
		printf("%s ", ptr->lastname);
	if ((ptr->isprint).firstname)
		printf("%s ", ptr->firstname);
	if ((ptr->isprint).ID)
		printf("%s ", ptr->ID);
	if ((ptr->isprint).salary)
		printf("%d ", ptr->salary);
	if ((ptr->isprint).age)
		printf("%d ", ptr->age);
	
	printf("\n");
	
	return;
}

void initPersonInfoSW(PersonInfo p[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		p[i].isprint.lastname = 0;
		p[i].isprint.firstname = 0;
		p[i].isprint.ID = 0;
		p[i].isprint.salary = 0;
		p[i].isprint.age = 0;
	}
	return;
}

void checkPersonInfostr(const char *s, PersonInfo p[], int n)
{
	int i;
	if (strcmp(s, "lastname") == 0)
		for (i = 0; i < n; i++)
			p[i].isprint.lastname = 1;
	
	if (strcmp(s, "firstname") == 0)
		for (i = 0; i < n; i++)
			p[i].isprint.firstname = 1;
	
	if (strcmp(s, "ID") == 0)
		for (i = 0; i < n; i++)
			p[i].isprint.ID = 1;
	
	if (strcmp(s, "salary") == 0)
		for (i = 0; i < n; i++)
			p[i].isprint.salary = 1;
	
	if (strcmp(s, "age") == 0)
		for (i = 0; i < n; i++)
			p[i].isprint.age = 1;
	
	return;
}

char* setPersonInfoSW(char *s, PersonInfo p[], int n)
{
	char *start = s;
	if (strncmp(s, "select", 6) != 0)
		return NULL;
	
	initPersonInfoSW(p, n);
	
	start = strtok(start, " ");
	while (start != NULL && strncmp(start, "where", 5) != 0) {
		//printf("%s\n", start);
		checkPersonInfostr(start, p, n);
		start = strtok(NULL, " ");
	}
	
	if (strncmp(start, "where", 5) == 0)
		start += 6;
	
	return start;
}

int where_condition(const char *sptr, PersonInfo *pptr)
{
	char buf[56];
	char comparsion[12];
	char operator[4];
	char condition[40];
	char *start = buf;
	
	strcpy(buf, sptr);
	start = strtok(start, " ");
	strcpy(comparsion, start);
	start = strtok(NULL, " ");
	strcpy(operator, start);
	start = strtok(NULL, " ");
	strcpy(condition, start);
	
	//printf("%s\n%s\n%s\n", comparsion, operator, condition);
	
	if (strcmp(comparsion, "lastname") == 0) {
		if (strcmp(operator, "==") == 0)
			return (strcmp(condition, pptr->lastname) == 0);
		
		if (strcmp(operator, "!=") == 0)
			return (strcmp(condition, pptr->lastname) != 0);
	}
	
	if (strcmp(comparsion, "firstname") == 0) {
		if (strcmp(operator, "==") == 0)
			return (strcmp(condition, pptr->firstname) == 0);
		
		if (strcmp(operator, "!=") == 0)
			return (strcmp(condition, pptr->firstname) != 0);
	}
	
	if (strcmp(comparsion, "ID") == 0) {
		if (strcmp(operator, "==") == 0)
			return (strcmp(condition, pptr->ID) == 0);
		
		if (strcmp(operator, "!=") == 0)
			return (strcmp(condition, pptr->ID) != 0);
	}
	
	if (strcmp(comparsion, "salary") == 0) {
		if (strcmp(operator, "==") == 0)
			return (atoi(condition) == pptr->salary);
		
		if (strcmp(operator, ">") == 0)
			return (atoi(condition) > pptr->salary);
		
		if (strcmp(operator, "<") == 0)
			return (atoi(condition) < pptr->salary);
	}
	
	if (strcmp(comparsion, "age") == 0) {
		if (strcmp(operator, "==") == 0)
			return (atoi(condition) == pptr->age);
		
		if (strcmp(operator, ">") == 0)
			return (atoi(condition) > pptr->age);
		
		if (strcmp(operator, "<") == 0)
			return (atoi(condition) < pptr->age);
	}
	
	return 1;
}

int main (void)
{
	int i, j;
	int n_data;
	int c_query;
	PersonInfo database[50];
	char input_buf[200];
	char *pt_where;
	
	scanf("%d", &n_data);
	for (i = 0; i < n_data; i++)
		inputPersonInfo(&(database[i]));
	
	scanf("%d", &c_query);
	gets(input_buf);
	for (i = 0; i < c_query; i++) {
		gets(input_buf);
		pt_where = setPersonInfoSW(input_buf, database, n_data);
		for (j = 0; j < n_data; j++)
			if (where_condition(pt_where, &(database[j])))
				printPersonInfo(&(database[j]));
	}
	
	return 0;
}
