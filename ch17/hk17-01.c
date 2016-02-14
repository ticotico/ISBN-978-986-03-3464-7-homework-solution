#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define debug 0

typedef struct linklist {
	int data;
	struct linklist *next;
}LinkList;

void print_list_forward(LinkList *head)
{
	for(; head != NULL; head = head->next) 
		printf("%d\n", head->data);
}

void print_list_backward(LinkList *head)
{
	LinkList *ptr = head;
	int list_size = 0;
	int *array;
	int i;
	
	for (; ptr != NULL; ptr = ptr->next)
		list_size++;
	array = (int *) malloc (sizeof(int) * list_size);
	assert(array != NULL);
	if (debug) printf("malloc int array [%d] %p\n", list_size, array);
	
	ptr = head;
	for (i = 0; i < list_size; i++) {
		array[i] = ptr->data;
		ptr = ptr->next;
	}
	for (i = list_size - 1; i >= 0; i--)
		printf("%d\n", array[i]);
	
	if(debug) printf("free int array[%d] %p\n", list_size, array);
	free(array);
}

void free_LinkList (LinkList *head)
{
	LinkList *next;
	while (head != NULL) {
		next = head->next;
		if (debug) printf("free LinkList * %p\n", head);
		free(head);
		head = next;
	}
}

int main (void)
{
	if(debug) printf("use debug\n");
	LinkList *head;
	LinkList *previous = NULL;
	int n;
	
	while (scanf("%d", &n) != EOF) {
		head = (LinkList *) malloc (sizeof(LinkList));
		assert(head != NULL);
		if (debug) printf("malloc LinkList * %p\n", head);
		head->data = n;
		head->next = previous;
		previous = head;
	}
	
	print_list_backward(head);
	
	free_LinkList(head);
	return 0;
}
