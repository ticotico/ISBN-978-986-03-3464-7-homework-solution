#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define debug 0

typedef struct bookshelf {
	int data;
	struct bookshelf *last;
	struct bookshelf *next;
	
}Bookshelf;

Bookshelf *find_book_by_book_num(Bookshelf *head, int book_num)
{
	Bookshelf *ptr = head;
	for (; ptr != NULL; ptr = ptr->next)
		if (ptr->data == book_num) return ptr;
	return NULL;
}

Bookshelf *find_final_book(Bookshelf *head)
{
	Bookshelf *ptr = head;
	Bookshelf *last = NULL;
	for (; ptr != NULL; ptr = ptr->next)
		last = ptr;
	return last;
}

Bookshelf *place_book(Bookshelf *head, int book_num, int shelf_size)
{
	static int book_count = 0;
	Bookshelf *current = find_book_by_book_num(head, book_num);
	Bookshelf *last;
	Bookshelf *next;
	//if new book is in shelf
	//take the book away and palce it in head
	if (current != NULL) {
		last = current->last;
		next = current->next;
		if (last != NULL) last->next = next;
		if (next != NULL) next->last = last;
		current->data = book_num;
		current->last = NULL;
		current->next = head;
		return current;
	}
	//if new book is not in shelf and shelf is not full
	//place new book
	if (current == NULL && book_count < shelf_size) {
		book_count++;
		current = (Bookshelf *) malloc (sizeof(Bookshelf));
		assert(current != NULL);
		if (debug) printf("malloc (Bookshelf *) at %p\n", current);
		current->data = book_num;
		current->last = NULL;
		current->next = head;
		if (head != NULL) head->last = current;
		return current;
	}
	//if new book is not in shelf and shelf is full
	//take the final book away and place new book
	if (current == NULL) {
		current = find_final_book(head);
		last = current->last;
		last->next = NULL;
		current->data = book_num;
		current->last = NULL;
		current->next = head;
		return current;
	}
	
	return NULL;
}

void print_Bookshelf(Bookshelf *head)
{
	Bookshelf *ptr;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
	putchar('\n');
}

void print_Bookshelf_reverse(Bookshelf *head, int size)
{
	int i;
	Bookshelf *ptr = head;
	int *output = (int *) malloc (size * sizeof(int));
	assert(output != NULL);
	if (debug) printf("malloc (int *) at %p\n", output);
	for (i = 0; i < size && ptr != NULL; i++) {
		output[i] = ptr->data;
		ptr = ptr->next;
	}
	for (i--; i >= 0; i--) printf("%d ", output[i]);
	putchar('\n');
	if (debug) printf("free (int *) at %p\n", output);
	free(output);
}

Bookshelf *delete_Bookshelf(Bookshelf *head)
{
	Bookshelf *ptr = head;
	Bookshelf *next = head;
	while (ptr != NULL) {
		next = ptr->next;
		if (debug) printf("free (Bookshelf *) at %p\n", ptr);
		free(ptr);
		ptr = next;
	}
	return ptr;
}

int main (void)
{
	Bookshelf *head = NULL;
	int n, m;
	int book_num;
	scanf("%d%d", &n, &m);
	
	while (scanf("%d", &book_num) != EOF) {
		assert(0 < book_num && book_num <= n);
		head = place_book(head, book_num, m);
		if (debug) print_Bookshelf(head);
	}
	print_Bookshelf_reverse(head, m);
	
	head = delete_Bookshelf(head);
	return 0;
}
