#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define debug 0

typedef struct employee{
	int id;
	char firstname[32];
	char lastname[32];
	struct employee *boss;
	
}Employee;

typedef struct person{
	char firstname[32];
	char lastname[32];
	
}Person;

void keyin_Employee(Employee *em)
{
	scanf("%d", &(em->id));
	scanf("%s", em->firstname);
	scanf("%s", em->lastname);
	
	return;
}

void keyin_Bossname (Person *bn)
{
	scanf("%s", bn->firstname);
	scanf("%s", bn->lastname);
	
	return;
}

void insert_Boss_ptr (Employee em[], Person bn[], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	for (j = 0; j < size; j++)
		if (strcmp(em[j].firstname, bn[i].firstname) == 0 &&
			strcmp(em[j].lastname, bn[i].lastname) == 0) {
				em[i].boss = &(em[j]);
				continue;
			}
	return;
}

void print_Employee(Employee *em, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("&em[%d] = %p\n", i, &(em[i]));
		printf("boss ptr = %p\n", em[i].boss);
		printf("id = %d\n", em[i].id);
		printf("%s %s\n", em[i].firstname, em[i].lastname);
		printf("\n");
	}
}

Employee *get_Employee_address (Employee em[], int n, char *firstname, char *lastname)
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(em[i].firstname, firstname) == 0 &&
			strcmp(em[i].lastname, lastname) == 0)
			return &(em[i]);
			
	return NULL;
}

int subordinate(Employee em[], Employee *A, Employee *B)
{
	Employee *current = A;
	for (; current->boss != current; current = current->boss)
		if (current->boss == B) return 1;
	
	return 0;
}

int supervisor(Employee em[], Employee *A, Employee *B)
{
	Employee *current = B;
	for (; current->boss != current; current = current->boss)
		if (current->boss == A) return 1;
	
	return 0;
}

int colleague(Employee em[], Employee *A, Employee *B)
{
	if (A->boss == B->boss)
		return 1;
	if (A->boss == A)
		return 0;
	if (B->boss == B)
		return 0;
	
	if (colleague(em, A->boss, B) || colleague(em, A, B->boss))
			return 1;
	
	return 0;
}

void print_relation(Employee em[], Employee *A, Employee *B)
{
	if (debug) printf("A = %p, B = %p\n", A, B);
	
	if (subordinate(em, A, B)) {
		printf("subordinate\n");
		return;
	}
	
	if (supervisor(em, A, B)) {
		printf("supervisor\n");
		return;
	}
	
	if (colleague(em, A, B)) {
		printf("colleague\n");
		return;
	}
	
	printf("unrelated\n");
	return;
}

int main (void)
{
	int i;
	int company_size;
	Employee *any_company = NULL;
	Person *boss_name;
	int m;
	char firstname[32], lastname[32];
	Employee *ptr_em_A, *ptr_em_B;
	
	scanf("%d", &company_size);
	any_company = (Employee *) malloc (company_size * sizeof(Employee));
	assert(any_company != NULL);
	if (debug) printf("malloc (Employee *) at %p\n", any_company);
	
	boss_name = (Person *) malloc (company_size * sizeof(Person));
	assert(boss_name != NULL);
	if (debug) printf("malloc (Person *) at %p\n", boss_name);
	
	for (i = 0; i < company_size; i++) {
		keyin_Employee(&(any_company[i]));
		keyin_Bossname(&(boss_name[i]));
	}
	
	insert_Boss_ptr(any_company, boss_name, company_size);
	
	if (debug) printf("free (Person *) at %p\n", boss_name);
	free(boss_name);
	
	if (debug) print_Employee(any_company, company_size);
	
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%s%s", firstname, lastname);
		ptr_em_A = get_Employee_address(any_company, 
					company_size, firstname, lastname);
		scanf("%s%s", firstname, lastname);
		ptr_em_B = get_Employee_address(any_company, 
					company_size, firstname, lastname);
		if (ptr_em_A == NULL || ptr_em_B == NULL) {
			printf("wrong input firstname or lastname\n");
			return -1;
		}
		print_relation(any_company, ptr_em_A, ptr_em_B);
	}
	
	if (debug) printf("free (Employee *) at %p\n", any_company);
	free(any_company);
	return 0;
}
