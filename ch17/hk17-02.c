#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define debug 0

typedef struct {
	int data;
	int level;
}InputDigit;

typedef struct treenode {
	int data;
	int level;
	struct treenode *left;
	struct treenode *right;
	
}TreeNode;

void print_preorder(TreeNode *root)
{
	if (root == NULL) return;
	printf("data = %d, level = %d\n", root->data, root->level);
	print_preorder(root->left);
	print_preorder(root->right);
}

TreeNode *insert_sort_bs_tree(TreeNode *node, int data, int lv)
{
	TreeNode *current;
	
	if(node == NULL) {
		current = (TreeNode *) malloc (sizeof(TreeNode));
		assert(current != NULL);
		current->data = data;
		current->level = lv;
		current->left = NULL;
		current->right = NULL;
		return current;
	}
	if (data <= node->data)
		node->left = insert_sort_bs_tree(node->left, data, lv);
	else
		node->right = insert_sort_bs_tree(node->right, data, lv);
	return node;
}

TreeNode *construct_bs_tree(InputDigit array[], int size)
{
	int i, j;
	int count = 0;
	TreeNode *root = NULL;
	
	for (i = 1; i <= size && count < size; i++)
		for (j = 0; j < size && count < size; j++)
			if (array[j].level == i) {
				count++;
				root = insert_sort_bs_tree(root, array[j].data, i);
			}
	return root;
}

TreeNode *delete_bs_tree(TreeNode *node)
{
	if (node == NULL)
		return NULL;
	delete_bs_tree(node->left);
	delete_bs_tree(node->right);
	free(node);
	return NULL;
}
int find_data(TreeNode *node, int data)
{
	if (node == NULL)
		return 0;
	if (node->data == data)
		return 1;
	
	return (find_data(node->left, data) || find_data(node->right, data));
}

TreeNode *find_co_subtree(TreeNode *root, int data1, int data2)
{
	if (root == NULL)
		return NULL;
	if (find_data(root->left, data1)
		&& find_data(root->left, data2))
		return find_co_subtree(root->left, data1, data2);
	if (find_data(root->right, data1)
		&& find_data(root->right, data2))
		return find_co_subtree(root->right, data1, data2);
	return root;
}

int data_to_level(TreeNode *root, int data)
{
	TreeNode *node = root;
	while (node != NULL) {
		if (data == node->data)
			return node->level;
		if (data <= node->data)
			node = node->left;
		else
			node = node->right;
	}
	return -1;
}

int main (void)
{
	int n, p;
	int i;
	int data1, data2;
	int level1, level2, co_root_level;
	InputDigit array[1000];
	TreeNode *root;
	TreeNode *co_root;
	
	scanf("%d", &n);
	for (i = 0; i < n ; i++) {
		scanf("%d", &(array[i].data));
		scanf("%d", &(array[i].level));
	}
	root = construct_bs_tree(array, n);
	if (debug) print_preorder(root);
	
	scanf("%d", &p);
	for (i = 0; i < p; i++) {
		scanf("%d%d", &data1, &data2);
		
		co_root = find_co_subtree(root, data1, data2);
		
		level1 = data_to_level(root, data1);
		level2 = data_to_level(root, data2);
		co_root_level = data_to_level(root, co_root->data);
		if (debug) printf("lv1 = %d, lv2 = %d, co_lv = %d\n",
							level1, level2, co_root_level);
		if (!debug) printf("%d\n", level1 + level2 - 2*co_root_level);
	}
	
	delete_bs_tree(root);
	return 0;
}
