#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define debug 0

typedef struct bs_tree {
	int data;
	struct bs_tree *left;
	struct bs_tree *right;
	
}BS_Tree;

BS_Tree *insert_sort_BS_Tree (BS_Tree *root, int data)
{
	BS_Tree *current = root;
	if (root == NULL) {
		current = (BS_Tree *) malloc (sizeof(BS_Tree));
		assert(current != NULL);
		if (debug) printf("malloc (BS_Tree *) at %p\n", current);
		current->data = data;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	
	if (data <= current->data)
		current->left = insert_sort_BS_Tree(current->left, data);
	else
		current->right = insert_sort_BS_Tree(current->right, data);
	
	return current;
}

int find_max_level(BS_Tree *root)
{
	int lv_left, lv_right;
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	
	lv_left = find_max_level(root->left);
	lv_right = find_max_level(root->right);
	return 1 + ((lv_left > lv_right) ? lv_left : lv_right);
}

void print_inorder (BS_Tree *root)
{
	if (root == NULL) return ;
	print_inorder(root->left);
	printf("data = %d\n", root->data);
	print_inorder(root->right);
}

void print_all_node(BS_Tree *root, int *output, int cur_lv)
{
	if (root == NULL) return ;
	output[cur_lv - 1] = root->data;
	
	if (root->left == NULL && root->right == NULL) {
		int i;
		for (i = 0; i < cur_lv; i++)
			printf("%d ", output[i]);
		putchar('\n');
		return;
	}
	
	print_all_node(root->left, output, cur_lv + 1);
	print_all_node(root->right, output, cur_lv + 1);
	return;
}

BS_Tree *delete_BS_Tree (BS_Tree *root)
{
	if (root == NULL) return NULL;
	delete_BS_Tree(root->left);
	delete_BS_Tree(root->right);
	if (debug) printf("free (BS_Tree *) at %p\n", root);
	free(root);
	return NULL;
}

int main (void)
{
	BS_Tree *root = NULL;
	int data;
	int max_lv;
	int *output = NULL;
	//creat tree by input data
	while (scanf("%d", &data) != EOF)
		root = insert_sort_BS_Tree(root, data);
	if (debug) print_inorder(root);
	//find max level of tree
	max_lv = find_max_level(root);
	if (debug) printf("max_lv = %d\n", max_lv);
	//malloc output int array by max level
	output = (int *) malloc ((max_lv + 1)* sizeof(int));
	assert(output != NULL);
	if (debug) printf("malloc (int *) at %p\n", output);
	//print output
	print_all_node(root, output, 1);
	//free malloc
	if (debug) printf("free (char *) at %p\n", output);
	free(output);
	root = delete_BS_Tree(root);
	return 0;
}
