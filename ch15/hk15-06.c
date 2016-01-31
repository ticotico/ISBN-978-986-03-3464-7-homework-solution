/*
兩個員工 A 跟 B 的關係定義如下:
 如果 A 可藉由一連串的「直屬上司」關係連到 B，則稱 A 是 B
 的部屬(subordinate)。
 如果 B 可藉由一連串的「直屬上司」關係連到 A，則稱 A 是 B
 的長官(supervisor)。
 如果 A 與 B 並非 subordinate / supervisor 關係，但存在另
 一個 C，且 A 與 B 皆為 C 的部屬。則 A 與 B 互為同事關係。
 (colleague)
 如果以上皆非，則 A 與 B 無關係(unrelated)。
輸入第一行為 n，代表員工數目。以下 n 行為員工號碼、姓、名、
直屬上司的員工號碼。我們假設所有直屬上司的資料都在這 n 筆資
料內，且員工沒有同名同姓。下一行為查詢次數 m ，以下 m 行為
想查詢的兩個員工姓名。員工姓名保證存在於輸入中，且代表兩不同
的員工。輸出有 m 行，美意行為想查詢的兩個員工姓名之間的關係。
*/
#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char firstname[32];
	char lastname[32];
	int boss_id;
} employee;

void keyin_employee(employee *em)
{
	scanf("%d", &(em->id));
	scanf("%s", em->firstname);
	scanf("%s", em->lastname);
	scanf("%d", &(em->boss_id));
	
	return;
}

int get_index (employee em[], int n, char *firstname, char *lastname)
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(em[i].firstname, firstname) == 0 &&
			strcmp(em[i].lastname, lastname) == 0)
			return i;
			
	return -1;
}

int get_boss_index(employee em[], int n, int A)
{
	int i;
	for (i = 0; i < n; i++)
		if (em[i].id == em[A].boss_id)
			return i;
	return -1;
}

int subordinate(employee em[], int n, int A, int B)
{
	int A_boss_index;
	int i;
	
	for (i = 0; i < n; i++) {
		if (em[A].boss_id == em[B].id)
			return 1;
		
		if (em[A].boss_id == em[A].id)
			return 0;
		
		A_boss_index = get_boss_index(em, n, A);
		A = A_boss_index;
	}
	
	return 0;
}

int supervisor(employee em[], int n, int A, int B)
{
	int B_boss_index;
	int i;
	
	for (i = 0; i < n; i++) {
		if (em[A].id == em[B].boss_id)
			return 1;
		
		if (em[B].id == em[B].boss_id)
			return 0;
		
		B_boss_index = get_boss_index(em, n, B);
		B = B_boss_index;
	}
	
	return 0;
}

int colleague(employee em[], int n, int A, int B)
{
	int A_boss_index, B_boss_index;
	
	if (em[A].boss_id == em[B].boss_id)
		return 1;
	if (em[A].id == em[A].boss_id)
		return 0;
	if (em[B].id == em[B].boss_id)
		return 0;
	
	A_boss_index = get_boss_index(em, n ,A);
	B_boss_index = get_boss_index(em, n, B);
	if (colleague(em, n, A_boss_index, B) ||
		colleague(em, n, A, B_boss_index))
			return 1;
	
	return 0;
}



void print_relation(employee em[], int n, int A, int B)
{
	//printf("A = %d, B = %d\n", A, B);
	
	if (subordinate(em, n, A, B)) {
		printf("subordinate\n");
		return;
	}
	
	if (supervisor(em, n, A, B)) {
		printf("supervisor\n");
		return;
	}
	
	if (colleague(em, n, A, B)) {
		printf("colleague\n");
		return;
	}
	
	printf("unrelated\n");
	return;
}

int main (void)
{
	int i;
	int n, m;
	employee any_company[32];
	char firstname[32], lastname[32];
	int employee_index_A, employee_index_B;
	
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		keyin_employee(&(any_company[i]));
	
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%s%s", firstname, lastname);
		employee_index_A = get_index(any_company, n, 
						firstname, lastname);
		scanf("%s%s", firstname, lastname);
		employee_index_B = get_index(any_company, n, 
						firstname, lastname);
		if (employee_index_A == -1 || employee_index_B == -1) {
			printf("wrong input firstname or lastname\n");
			return -1;
		}
		print_relation(any_company, n, employee_index_A, employee_index_B);
	}
	
	return 0;
}
