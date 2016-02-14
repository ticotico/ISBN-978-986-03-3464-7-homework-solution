#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define debug 0

typedef struct  event_tree {
	char data;
	struct event_tree *ptr[3];
	
}EventTree;

EventTree *find_data (EventTree *root, char data)
{
	EventTree *result;
	int i;
	if (root == NULL || root->data == data)
		return root;
	for (i = 0; i < 3; i++) {
		result = find_data(root->ptr[i], data);
		if (result != NULL) return result;		
	}

	return NULL;
}

EventTree *insert_EventTree (EventTree *root,
	char root_data, char node_data[], int node_size)
{
	EventTree *current;
	EventTree *subtree_ptr[3] = {NULL, NULL, NULL};
	int i, j;
	current = find_data(root, root_data);
	
	for (i = 0; i < node_size; i++) {
		subtree_ptr[i] = (EventTree *) malloc (sizeof(EventTree));
		assert(subtree_ptr[i] != NULL);
		if (debug) printf("malloc EventTree at %p\n", subtree_ptr[i]);
		subtree_ptr[i]->data = node_data[i];
		for (j = 0; j < 3; j++) subtree_ptr[i]->ptr[j] = NULL;
	}
	for (; i < 3; i++) subtree_ptr[i] = NULL;
	
	if (current == NULL) {
		current = (EventTree *) malloc (sizeof(EventTree));
		assert(current != NULL);
		if (debug) printf("malloc EventTree at %p\n", current);
		current->data = root_data;
		for (j = 0; j < 3; j++) current->ptr[j] = subtree_ptr[j];
		return current;
	}
	
	for (j = 0; j < 3; j++) current->ptr[j] = subtree_ptr[j];
	return root;
}

void *delete_EventTree (EventTree *root)
{
	int i;
	if (root == NULL) return;
	for (i = 0; i < 3; i++)
		delete_EventTree(root->ptr[i]);
	printf("free (EventTree *)%p\n", root);
	free(root);
}

int main (void)
{
	int i, j;
	int n, e;
	char root_data, sub_data[3];
	EventTree *root = NULL;
	int m;
	char data_A, data_B;
	EventTree *find_root;
	
	scanf("%d", &n);
	if (debug) printf("n = %d\n", n);
	getchar();
	for (i = 0; i < n; i++) {
		if (debug) printf("in loop, i = %d\n", i);
		scanf("%c", &root_data);
		getchar();
		scanf("%d", &e);
		getchar();
		for (j = 0; j < e; j++) {
			scanf("%c", &(sub_data[j]));
			getchar();
		}
			
		if (debug) printf("%c %d ", root_data, e);
		if (debug) for (j = 0 ; j < e; j++) printf("%c ", sub_data[j]);
		if(debug) putchar('\n');
		root = insert_EventTree(root, root_data, sub_data, e);
	}
	
	scanf("%d", &m);
	if (debug) printf("m = %d\n", m);
	getchar();
	for (i = 0; i < m; i++) {
		data_A = getchar();
		getchar();
		data_B = getchar();
		getchar();
		if (debug) printf("%c %c\n", data_A, data_B);
		
		find_root = find_data(root, data_A);
		if (find_data(find_root, data_B) != NULL)
			printf("yes\n");
		else
			printf("no\n");
	}
	delete_EventTree(root);
	return 0;
}
